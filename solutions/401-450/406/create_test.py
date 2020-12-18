from __future__ import print_function

import random, json

def dump(question, answer):
  print(''.join(json.dumps(question).split()))
  print(''.join(json.dumps(answer).split()))

def generate(max_height=10, amount=10):
  answer = [[random.randint(0, max_height), 0] for _ in range(amount)]
  for i in range(len(answer)):
    for j in range(i + 1, len(answer)):
      if answer[i][0] >= answer[j][0]:
        answer[j][1] += 1
  question = list(answer)
  random.shuffle(question)
  dump(question, answer)

# Test 1
dump([[1,0]], [[1,0]])

# Test 2
dump([[0,4],[0,3],[0,1],[0,0],[0,2]],[[0,0],[0,1],[0,2],[0,3],[0,4]])

# Test 3
generate(1e1, 10)

# Test 4
generate(1e2, 50)

# Test 5
generate(1e3, 100)

# Test 6
generate(1e4, 500)

# Test 7
generate(1e5, 1000)

# Test 8
generate(1e6, 2000)
