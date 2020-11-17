from __future__ import print_function

import random

def generate_numbers(length=10):
  s = ''.join([random.choice('0123456789') for _ in range(length - 1)])
  s = random.choice('123456789') + s
  return long(s)

def print_test(a, b):
  print(str(a)[::-1])
  print(str(b)[::-1])
  print(str(a + b)[::-1])

# Test 1
print_test(0, 0)

# Test 2
print_test(123, 567)

# Test 3
print_test(456, 633)

# Test 4
print_test(121, 80)

# Test 5
print_test(9, 999991)

# Test 6
print_test(1111119, 1)

# Test 7
print_test(generate_numbers(40), generate_numbers(60))

# Test 8
print_test(generate_numbers(10), generate_numbers(90))

# Test 9
print_test(generate_numbers(99), generate_numbers(99))

# Test 10
print_test(long('9'*99), generate_numbers(99))
