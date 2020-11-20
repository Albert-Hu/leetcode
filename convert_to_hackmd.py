from __future__ import print_function

import argparse, os, re

def list_dirs(root_path):
  return list(filter(lambda d: os.path.isdir(os.path.join(root_path, d)), os.listdir(root_path)))

def convert(output_dir):
  if not os.path.exists(output_dir):
    os.mkdir(output_dir)
  solution_dir = 'solutions'
  groups = list_dirs(solution_dir)
  groups.sort(key=lambda x: int(x.split('-')[0]))
  for group in groups:
    group_path = os.path.join(solution_dir, group)
    problems = list_dirs(os.path.join(group_path))
    problems.sort(key=lambda x: int(x))
    for problem in problems:
      problem_path = os.path.join(group_path, problem)
      readme_path = os.path.join(problem_path, 'README.md')
      solution_md = os.path.join(problem_path, 'Solution.md')
      if not os.path.exists(solution_md):
        continue
      if os.path.getsize(solution_md) == 0:
        continue
      document = ''
      with open(readme_path, 'r') as readme:
        content = readme.readlines()
        content[0] = ' '.join(content[0].split()[1:])
        content[0] = '# {}. {}'.format(problem, content[0])
        for line in range(len(content)):
          if content[line] == 'See the [solution](Solution.md).\n':
            break
          if re.match(r'!\[.+\]\(.+\)\n', content[line]):
            url = '(https://github.com/Albert-Hu/leetcode/blob/master/solutions/{}/{}/'.format(group, problem)
            content[line] = content[line].replace('(', url)
          document += content[line]
      with open(solution_md) as solution:
        document += '\n---\n\n' + solution.read()
      document += 'See the full [solution](https://github.com/Albert-Hu/leetcode/tree/master/solutions/{}/{}).\n'.format(group, problem)
      document += '\n\n###### tags: `leetcode`'
      tags_path = os.path.join(problem_path, 'tags')
      with open(tags_path, 'r') as tag:
        for tag_str in tag.readlines():
          tag_str = tag_str.replace('\n', '')
          tag_str = tag_str.replace('[', '')
          tag_str = tag_str.replace(']', '')
          document += ' `{}`'.format(tag_str)
      document_path = os.path.join(output_dir, '{}.md'.format(problem))
      with open(document_path, 'w') as doc:
        doc.write(document)
      print('Created the {}.md -> {}'.format(problem, document_path))

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--output', help='The output folder.', default='hackmd')
  args = parser.parse_args()
  convert(args.output)
