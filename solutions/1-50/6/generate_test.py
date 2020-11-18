from __future__ import print_function

import random, string

def dump(n, test, answer):
  print(n)
  print(test)
  print(answer)

def convert(s, r):
  if len(s) == 1 or r == 1 or len(s) <= r:
    return s
  answer = ''
  for i in range(r):
    index = i
    interval = r + r - 2
    _next = 0
    skip = [
      interval - ((i * 2) % interval),
      interval - ((interval - i * 2) % interval)]
    while index < len(s):
      answer += s[index]
      index += skip[_next]
      _next = (_next + 1) % 2
  return answer

def generate(n, r):
  characters = string.ascii_lowercase + string.ascii_uppercase + ',.'
  test = ''.join([random.choice(characters) for _ in range(n)])
  answer = convert(test, r)
  dump(r, test, answer)

# Test 1
generate(1, 1)

# Test 2
generate(1, 2)

# Test 3
generate(1, 3)

# Test 4
generate(2, 1)

# Test 5
generate(2, 2)

# Test 6
generate(2, 3)

# Test 7
generate(10, 1)

# Test 8
generate(1, 10)

# Test 9
generate(4, 5)

# Test 10
generate(5, 4)

# Test 11
generate(100, 100)

# Test 12
generate(1000, 50)

# Test 13
generate(50, 1000)

# Test 14
generate(1000, 1000)
