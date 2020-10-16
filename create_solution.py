from __future__ import print_function
from distutils.dir_util import copy_tree

import argparse, os

def copy(dest):
  if os.path.exists(dest):
    print('The solution already exists.')
  else:
    copy_tree('template', dest)

if __name__ == '__main__':
  args = argparse.ArgumentParser()
  args.add_argument('path', help='Path to solution.', type=str)
  copy(args.parse_args().path)
