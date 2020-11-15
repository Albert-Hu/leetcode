from __future__ import print_function

import random

'''
The inputs are repeating by:
1. Target
2. Numbers
3. Answer
'''

def dump_test(test):
  print(str(test[0]))
  print(' '.join([str(n) for n in test[1]]))
  print('{} {}'.format(test[2][0], test[2][1]))

def generate_test(start=-1e9, end=1e9, amount=100):
  array = [random.randrange(start, end) for _ in range(amount)]
  indices = list(range(amount))
  indices.sort(key=lambda i: array[i])
  if random.choice([True, False]):
    answer = [indices[-1], indices[-2]]
    array[indices[-1]] = array[indices[-1]] + 2
    array[indices[-2]] = array[indices[-2]] + 1
    target = array[indices[-1]] + array[indices[-2]]
  else:
    answer = [indices[0], indices[1]]
    array[indices[0]] = array[indices[0]] - 2
    array[indices[1]] = array[indices[1]] - 1
    target = array[indices[0]] + array[indices[1]]
  return target, array, answer

# Test 1
print('0')
print('0 0')
print('0 1')

# Test 2
print('0')
print('1 -1')
print('0 1')

# Test 3
print('-999')
print('1 -1000')
print('0 1')

# Test 4
print('5')
print('1 2 3')
print('1 2')

# Test 5
print('4')
print('1 2 3')
print('0 2')

# Test 6
print('3')
print('1 2 3')
print('0 1')

# Test 7
dump_test(generate_test(-10, 10, 10))

# Test 8
dump_test(generate_test(-100, 100, 100))

# Test 9
dump_test(generate_test(-1000, 1000, 1000))

# Test 10
dump_test(generate_test(int(-1e8), int(1e8), int(1e5)))
