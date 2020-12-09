from __future__ import print_function
from distutils.dir_util import copy_tree

import argparse, os

def copy(number):
  upper_bound = int((number + 49) / 50) * 50
  group = '{}-{}'.format(int(upper_bound - 49), int(upper_bound))
  dest = os.path.join('solutions', group, str(number))
  if os.path.exists(dest):
    print('The solution already exists.')
  else:
    copy_tree('template', dest)
    print('created a new solution at {}'.format(dest))

if __name__ == '__main__':
  args = argparse.ArgumentParser()
  args.add_argument('number', help='The number of problem.', type=int)
  copy(args.parse_args().number)
