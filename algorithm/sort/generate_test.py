from __future__ import print_function

import argparse, random

def generate(minimum, maximum, total_number):
  maximum += 1
  for _ in range(total_number):
    print(random.randrange(minimum, maximum), end=' ')
  print('')

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--minimum', help='The minimum number in array.', type=int, default=-10)
  parser.add_argument('--maximum', help='The maximum number in array.', type=int, default=10)
  parser.add_argument('--total-number', help='Total number in the array.', type=int, default=10)
  args = parser.parse_args()
  generate(**args.__dict__)
