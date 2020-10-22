from __future__ import print_function

import os

def update_readme(path, content):
  with open(path, 'w') as readme:
    readme.write(content)
  print('updated {}.'.format(path))

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
    problem_path = os.path.join(group_path, problem)
    with open(os.path.join(problem_path, 'README.md'), 'r') as readme:
      title = ' '.join(readme.readline().split()[1:])
    incomplete = '(incomplete)'
    solution_md = os.path.join(problem_path, 'Solution.md')
    if os.path.exists(solution_md):
      if os.path.getsize(solution_md) > 0:
        incomplete = ''
    content += '- {}, [{}]({}/{}/README.md){}\n'.format(problem, title, group, problem, incomplete)
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
    problem_path = os.path.join(group_path, problem)
    with open(os.path.join(problem_path, 'README.md'), 'r') as readme:
      title = ' '.join(readme.readline().split()[1:])
    incomplete = '(incomplete)'
    solution_md = os.path.join(problem_path, 'Solution.md')
    if os.path.exists(solution_md):
      if os.path.getsize(solution_md) > 0:
        incomplete = ''
    content += '{}, [{}]({}/README.md){}\n'.format(problem, title, problem, incomplete)
  content += '\n'
  update_readme(readme_path, content)
