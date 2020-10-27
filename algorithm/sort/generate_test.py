from __future__ import print_function
from random import randrange

import argparse

def generate(minimum, maximum, total_number, descending=False, random=False):
  if random:
    for _ in range(total_number):
      print(randrange(minimum, maximum + 1), end=' ')
  else:
    if descending:
      for num in range(maximum, minimum - 1, -1):
        print(num, end=' ')
    else:
      for num in range(minimum, maximum + 1):
        print(num, end=' ')
  print('')

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--minimum', help='The minimum number in array.', type=int, default=-10)
  parser.add_argument('--maximum', help='The maximum number in array.', type=int, default=10)
  parser.add_argument('--total-number', help='Total number in the array.', type=int, default=10)
  parser.add_argument('--random', help='Generate the array at random.', action='store_true')
  parser.add_argument('--descending', help='Generate the descending array.', action='store_true')
  args = parser.parse_args()
  generate(**args.__dict__)
