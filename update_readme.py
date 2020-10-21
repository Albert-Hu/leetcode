from __future__ import print_function

import os

cnt = 0

def update_readme(path, content):
  with open(path, 'w') as readme:
    readme.write(content)
  print('updated {}.'.format(path))
  cnt += 1

root = 'solutions'
groups = os.listdir(root)
groups.sort(key=lambda x: int(x.split('-')[0]))

# generate README.md under the solutions.
content = ''
for group in groups:
  group_path = os.path.join(root, group)
  content += '# {}\n\n'.format(group)
  problems = os.listdir(group_path)
  problems.sort(key=lambda x: int(x))
  for problem in problems:
    with open(os.path.join(group_path, problem, 'README.md'), 'r') as readme:
      title = ' '.join(readme.readline().split()[1:])
    content += '- {}, [{}]({}/{}/README.md)\n'.format(problem, title, group, problem)
  content += '\n'
update_readme(os.path.join(root, 'README.md'), content)

# generate README.md for each directory under the solutions.
for group in groups:
  group_path = os.path.join(root, group)
  readme_path = os.path.join(group_path, 'README.md')
  content = ''
  problems = os.listdir(os.path.join(group_path))
  problems.sort(key=lambda x: int(x))
  for problem in problems:
    with open(os.path.join(group_path, problem, 'README.md'), 'r') as readme:
      title = ' '.join(readme.readline().split()[1:])
    content += '{}, [{}]({}/README.md)\n'.format(problem, title, problem)
  content += '\n'
  update_readme(readme_path, content)

print('{} files are updated.'.format(cnt))
