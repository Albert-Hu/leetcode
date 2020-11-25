from __future__ import print_function

import string, random

def dump(s, ans):
  print(s)
  print(ans)

def random_select(s, l):
  return ''.join([random.choice(s) for _ in range(l)])

# Test 1
dump('', 0)

# Test 2
dump('a', 1)

# Test 3
dump('aa', 1)

# Test 4
dump('aaaaaaa', 1)

# Test 5
dump('a' * int(5*1e4), 1)

s = string.ascii_letters
s += string.digits
s += ' ~!@#$%^&*()_+{}|<>?`-=[]\\,./;\':"'

# Test 6
s = list(s)
random.shuffle(s)
s = ''.join(s)
dump(s, len(s))

# Test 7
s = list(s)
random.shuffle(s)
s = ''.join(s)
dump(s + random_select(s, 11), len(s))

# Test 8
s = list(s)
random.shuffle(s)
s = ''.join(s)
dump(random_select(s, 13) + s, len(s))

# Test 9
s = list(s)
random.shuffle(s)
s = ''.join(s)
dump(random_select(s, 7) + s + random_select(s, 29), len(s))
