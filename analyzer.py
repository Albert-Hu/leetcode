from __future__ import print_function

from urllib import request
from datetime import date
from pytablewriter import MarkdownTableWriter
from pytablewriter.style import Style

import os, json, argparse
import pandas


LEETCODE_API = {
  'tags': 'https://leetcode.com/problems/api/tags',
  'all': 'https://leetcode.com/api/problems/all'
}

LEVELS = {
  1: 'Easy',
  2: 'Medium',
  3: 'Hard'
}

def download(to, override=True):
  if not os.path.exists(to):
    os.mkdir(to)
  headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36'}
  for name, url in LEETCODE_API.items():
    file_path = os.path.join(to, name + '.json')
    if os.path.exists(file_path) and not override:
      continue
    req = request.Request(url, headers=headers)
    with request.urlopen(req) as content:
      with open(file_path, 'w') as file:
        file.write(content.read().decode('utf8'))
      print('Download {}.'.format(file_path))

def load(directory):
  data = {}
  for name, _ in LEETCODE_API.items():
    file_path = os.path.join(directory, name + '.json')
    with open(file_path, 'r') as file:
      data[name] = json.loads(file.read())
  # convert the List to the Set for the performance of the search
  for topic in data['tags']['topics']:
    topic['questions'] = set(topic['questions'])
  questions = {}
  for q in data['all']['stat_status_pairs']:
    qid = q['stat']['frontend_question_id']
    releated_topics = filter(lambda t: qid in t['questions'], data['tags']['topics'])
    releated_topics = sorted(set([t['slug'] for t in releated_topics]))
    # add the quetion if the it is not locked
    if len(releated_topics) > 0:
      questions[qid] = {
        'title': q['stat']['question__title'],
        'title_slug': q['stat']['question__title_slug'],
        'accepted': q['stat']['total_acs'],
        'submissions': q['stat']['total_submitted'],
        'acceptance': 100. * q['stat']['total_acs'] / q['stat']['total_submitted'],
        'level': q['difficulty']['level'],
        'topics': releated_topics,
        'topics_str': ';'.join(releated_topics)
      }
  topics = data['tags']['topics']
  for t in topics:
    t['questions'] = set(filter(lambda qid: qid in questions.keys(), t['questions']))
    t['difficulty'] = {}
    t['difficulty']['easy'] = set(filter(lambda qid: questions[qid]['level'] == 1, t['questions']))
    t['difficulty']['medium'] = set(filter(lambda qid: questions[qid]['level'] == 2, t['questions']))
    t['difficulty']['hard'] = set(filter(lambda qid: questions[qid]['level'] == 3, t['questions']))
    # group the similar questions
    t['similarities'] = {}
    topic_groups = {
      questions[qid]['topics_str']: questions[qid]['topics'] for qid in t['questions']}
    for name, group in topic_groups.items():
      _topics = set(filter(lambda topic_name: topic_name != t['slug'], group))
      if len(_topics) > 1:
        t['similarities'][name] = {
          'questions': set(filter(lambda qid: questions[qid]['topics_str'] == name, t['questions'])),
          'topics': _topics
        }
  return topics, questions

def generate_markdown(to, topics, questions):
  timestamp = 'latest updated at {}'.format(date.today().strftime("%Y/%m/%d"))
  # generate to questions.md
  question_json = {
    'Number': [],
    'Title': [],
    'Level': [],
    'Accepted': [],
    'Submissions': [],
    'Acceptance': []
  }
  number = '{:,}'
  acceptance = '{:.0f}%'
  title = '[{}](https://leetcode.com/problems/{})'
  easy = 0
  medium = 0
  hard = 0
  for qid in sorted(questions.keys()):
    q = questions[qid]
    question_json['Number'].append(qid)
    question_json['Title'].append(title.format(q['title'], q['title_slug']))
    question_json['Level'].append(LEVELS[q['level']])
    question_json['Accepted'].append(number.format(q['accepted']))
    question_json['Submissions'].append(number.format(q['submissions']))
    question_json['Acceptance'].append(acceptance.format(q['acceptance']))
    if q['level'] == 1: easy += 1
    if q['level'] == 2: medium += 1
    if q['level'] == 3: hard += 1
  questions_md = os.path.join(to, 'questions.md')
  with open(questions_md, 'w') as md:
    total = len(questions.keys())
    md.write('# List of All Questions\n\n')
    md.write('**Total Questions: {}, Easy: {}, Medium: {}, Hard: {}, {}.**\n\n'.format(
      total,
      easy,
      medium,
      hard,
      timestamp))
    table = pandas.DataFrame.from_dict(question_json)
    writer = MarkdownTableWriter()
    writer.from_dataframe(table)
    writer.column_styles = [
        Style(align="right"),
        Style(align="left"),
        Style(align="center"),
        Style(align="right"),
        Style(align="right"),
        Style(align="right")
    ]
    md.write(writer.dumps())
    md.write('\n\n')
    print('Created {}.'.format(questions_md))
  # generate to topics.md
  topic_slug_to_name = {}
  name = '[{}]({}.md)'
  topic_json = {
    'Name': [],
    'Total': [],
    'Easy': [],
    'Medium': [],
    'Hard': []
  }
  for t in topics:
    topic_slug_to_name[t['slug']] = t['name']
    topic_json['Name'].append(name.format(t['name'], t['slug']))
    topic_json['Total'].append(number.format(len(t['questions'])))
    topic_json['Easy'].append(number.format(len(t['difficulty']['easy'])))
    topic_json['Medium'].append(number.format(len(t['difficulty']['medium'])))
    topic_json['Hard'].append(number.format(len(t['difficulty']['hard'])))
  topics_md = os.path.join(to, 'topics.md')
  with open(topics_md, 'w') as md:
    md.write('# List of All Topics\n\n')
    md.write('**Total Questions: {}, Easy: {}, Medium: {}, Hard: {}, {}.**\n\n'.format(
      total,
      easy,
      medium,
      hard,
      timestamp))
    table = pandas.DataFrame.from_dict(topic_json)
    writer = MarkdownTableWriter()
    writer.from_dataframe(table)
    writer.column_styles = [
        Style(align="left"),
        Style(align="right"),
        Style(align="right"),
        Style(align="right"),
        Style(align="right")
    ]
    md.write(writer.dumps())
    md.write('\n\n')
    print('Created {}.'.format(topics_md))
  # generate to each of topics
  for t in topics:
    topic_name_md = os.path.join(to, t['slug'] + '.md')
    with open(topic_name_md, 'w') as md:
      total = len(t['questions'])
      easy = 0
      medium = 0
      hard = 0
      for qid in t['questions']:
        if questions[qid]['level'] == 1: easy += 1
        if questions[qid]['level'] == 2: medium += 1
        if questions[qid]['level'] == 3: hard += 1
      md.write('# List of All Questions in {}\n\n'.format(t['name']))
      md.write('**Total Questions: {}, Easy: {}, Medium: {}, Hard: {}, {}.**\n\n'.format(
        total,
        easy,
        medium,
        hard,
        timestamp))
      md.write('- [{}](#{})\n'.format(t['name'], t['name'].replace(' ', '-')))
      for k in sorted(t['similarities'].keys()):
        similarity_topics = map(lambda _t: topic_slug_to_name[_t], t['similarities'][k]['topics'])
        similarity_topics = sorted(similarity_topics)
        md.write('- [{}](#{})\n'.format(', '.join(similarity_topics), '-'.join(similarity_topics).replace(' ', '-')))
      md.write('\n')
      question_json = {
        'Number': [],
        'Title': [],
        'Level': [],
        'Accepted': [],
        'Submissions': [],
        'Acceptance': []
      }
      for qid in sorted(t['questions']):
        if len(questions[qid]['topics']) == 1:
          q = questions[qid]
          question_json['Number'].append(qid)
          question_json['Title'].append(title.format(q['title'], q['title_slug']))
          question_json['Level'].append(LEVELS[q['level']])
          question_json['Accepted'].append(number.format(q['accepted']))
          question_json['Submissions'].append(number.format(q['submissions']))
          question_json['Acceptance'].append(acceptance.format(q['acceptance']))
      md.write('## {}\n\n'.format(t['name']))
      table = pandas.DataFrame.from_dict(question_json)
      writer = MarkdownTableWriter()
      writer.from_dataframe(table)
      writer.column_styles = [
          Style(align="right"),
          Style(align="left"),
          Style(align="center"),
          Style(align="right"),
          Style(align="right"),
          Style(align="right")
      ]
      md.write(writer.dumps())
      md.write('\n\n')
      for k in sorted(t['similarities'].keys()):
        question_json = {
          'Number': [],
          'Title': [],
          'Level': [],
          'Accepted': [],
          'Submissions': [],
          'Acceptance': []
        }
        similarity_topics = map(lambda _t: topic_slug_to_name[_t], t['similarities'][k]['topics'])
        similarity_topics = sorted(similarity_topics)
        similarity_questions = sorted(t['similarities'][k]['questions'])
        for qid in similarity_questions:
          q = questions[qid]
          question_json['Number'].append(qid)
          question_json['Title'].append(title.format(q['title'], q['title_slug']))
          question_json['Level'].append(LEVELS[q['level']])
          question_json['Accepted'].append(number.format(q['accepted']))
          question_json['Submissions'].append(number.format(q['submissions']))
          question_json['Acceptance'].append(acceptance.format(q['acceptance']))
        md.write('## {}\n\n'.format(', '.join(similarity_topics)))
        table = pandas.DataFrame.from_dict(question_json)
        writer = MarkdownTableWriter()
        writer.from_dataframe(table)
        writer.column_styles = [
            Style(align="right"),
            Style(align="left"),
            Style(align="center"),
            Style(align="right"),
            Style(align="right"),
            Style(align="right")
        ]
        md.write(writer.dumps())
        md.write('\n\n')
      print('Created {}.'.format(topic_name_md))

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('-o', '--output-dir',
    required=True,
    help='That the path of the output directory.')
  parser.add_argument('-u', '--update',
    action='store_true',
    help='Update the data from LeetCode.')
  parser.add_argument('-m', '--markdown',
    action='store_true',
    help='Generate to Markdown files.')
  args = parser.parse_args()
  # download data from LeetCode if need
  download(args.output_dir, args.update)
  # load the data
  topics, questions = load(args.output_dir)
  # generate to Markdown if need
  if args.markdown:
    generate_markdown(args.output_dir, topics, questions)
