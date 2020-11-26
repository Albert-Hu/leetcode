from __future__ import print_function

import argparse, os, re

HACKMD_URL = 'https://hackmd.io/@Albert-Hu'
IMG_URL = 'https://raw.githubusercontent.com/Albert-Hu/leetcode/master/solutions'
SOLUTION_URL = 'https://github.com/Albert-Hu/leetcode/tree/master/solutions'

def list_dirs(root_path):
  return list(filter(lambda d: os.path.isdir(os.path.join(root_path, d)), os.listdir(root_path)))

def convert(output_dir):
  if not os.path.exists(output_dir):
    os.mkdir(output_dir)
  solution_dir = 'solutions'
  links = {
    'by_number': [],
    'by_level': { 'Easy': [], 'Medium': [], 'Hard': [] },
    'by_class': {}}
  # Go through every group.
  groups = list_dirs(solution_dir)
  groups.sort(key=lambda x: int(x.split('-')[0]))
  for group in groups:
    group_path = os.path.join(solution_dir, group)
    problems = list_dirs(os.path.join(group_path))
    problems.sort(key=lambda x: int(x))
    # Go through every problem.
    for problem in problems:
      problem_path = os.path.join(group_path, problem)
      readme_path = os.path.join(problem_path, 'README.md')
      solution_md = os.path.join(problem_path, 'Solution.md')
      if not os.path.exists(solution_md):
        continue
      if os.path.getsize(solution_md) == 0:
        continue
      title = ''
      document = ''
      with open(readme_path, 'r') as readme:
        content = readme.readlines()
        content[0] = ' '.join(content[0].split()[1:])
        content[0] = '# {}. {}'.format(problem, content[0])
        title = content[0].replace('# ', '')
        for line in range(len(content)):
          if content[line] == 'See the [solution](Solution.md).\n':
            break
          if re.match(r'!\[.+\]\(.+\)\n', content[line]):
            url = '({}/{}/{}/'.format(IMG_URL, group, problem)
            content[line] = content[line].replace('(', url)
          document += content[line]
      with open(solution_md) as solution:
        document += '\n---\n\n' + solution.read()
      document += '\nSee the full [solution]({}/{}/{}).\n'.format(SOLUTION_URL, group, problem)
      document += '\n\n###### tags: `leetcode`'
      document_link = '- [{}]({}/leetcode-{})\n'.format(title, HACKMD_URL, problem)
      tags_path = os.path.join(problem_path, 'tags')
      with open(tags_path, 'r') as tag:
        for tag_str in tag.readlines():
          tag_str = tag_str.replace('\n', '')
          if tag_str in ['[Easy]', '[Medium]', '[Hard]']:
            tag_str = tag_str.replace('[', '')
            tag_str = tag_str.replace(']', '')
            links['by_level'][tag_str].append(document_link)
          else:
            if tag_str not in links['by_class'].keys():
              links['by_class'][tag_str] = []
            links['by_class'][tag_str].append(document_link)
          document += ' `{}`'.format(tag_str)
      document_path = os.path.join(output_dir, '{}.md'.format(problem))
      with open(document_path, 'w') as doc:
        doc.write(document)
      links['by_number'].append(document_link)
      print('Created the {}.md -> {}'.format(problem, document_path))
  with open(os.path.join(output_dir, 'category_by_number.md'), 'w') as category:
    category.write('# Leetcode Solutions\n\n')
    category.write('See the [solutions]({}/leetcode-category-by-level) in a category by level.\n'.format(HACKMD_URL))
    category.write('See the [solutions]({}/leetcode-category-by-class) in a category by class.\n\n'.format(HACKMD_URL))
    category.write('## The Problems:\n\n')
    category.writelines(links['by_number'])
    category.write('\n\n###### tags: `leetcode`')
  print('Create the category_by_number.md -> {}/category_by_number.md'.format(output_dir))
  with open(os.path.join(output_dir, 'category_by_class.md'), 'w') as category:
    category.write('# Leetcode Solutions Category by Class\n\n')
    category.write('See the [solutions]({}/leetcode-category-by-number) in a category by number.\n'.format(HACKMD_URL))
    category.write('See the [solutions]({}/leetcode-category-by-level) in a category by level.\n\n'.format(HACKMD_URL))
    classes = links['by_class'].keys()
    classes.sort()
    for _class in classes:
      category.write('## {}\n\n'.format(_class))
      category.writelines(links['by_class'][_class])
      category.write('\n')
    category.write('\n\n###### tags: `leetcode`')
  print('Create the category_by_class.md -> {}/category_by_class.md'.format(output_dir))
  with open(os.path.join(output_dir, 'category_by_level.md'), 'w') as category:
    category.write('# Leetcode Solutions Category by Level\n\n')
    category.write('See the [solutions]({}/leetcode-category-by-number) in a category by number.\n'.format(HACKMD_URL))
    category.write('See the [solutions]({}/leetcode-category-by-class) in a category by class.\n\n'.format(HACKMD_URL))
    if len(links['by_level']['Easy']) > 0:
      category.write('## Easy\n\n')
      category.writelines(links['by_level']['Easy'])
      category.write('\n')
    if len(links['by_level']['Medium']) > 0:
      category.write('## Medium\n\n')
      category.writelines(links['by_level']['Medium'])
      category.write('\n')
    if len(links['by_level']['Hard']) > 0:
      category.write('## Hard\n\n')
      category.writelines(links['by_level']['Hard'])
      category.write('\n')
    category.write('\n\n###### tags: `leetcode`')
  print('Create the category_by_level.md -> {}/category_by_level.md'.format(output_dir))


if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--output', help='The output folder.', default='hackmd')
  args = parser.parse_args()
  convert(args.output)
