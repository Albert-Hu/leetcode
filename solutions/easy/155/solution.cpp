#include <iostream>
#include <vector>

using namespace std;

static auto _______ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

#if 1
class MinStack {
public:
  MinStack() {}

  void push(int x) {
    if (heap.empty() || x <= getMin())
      heap.push_back(x);
    stack.push_back(x);
  }

  void pop() {
    if (stack.back() == heap.back())
      heap.pop_back();
    stack.pop_back();
  }

  int top() {
    return stack.back();
  }

  int getMin() {
    return heap.back();
  }

private:
  vector<int> heap;
  vector<int> stack;
};
#else
class MinStack {
public:
  MinStack() : minimum(INT32_MAX) {
  }

  void push(int x) {
    stack.push_back(x);
    if (x < minimum) minimum = x;
  }

  void pop() {
    stack.pop_back();
    minimum = INT32_MAX;
    for (auto x : stack) {
      if (x < minimum) minimum = x;
    }
  }

  int top() {
    return stack.back();
  }

  int getMin() {
    return minimum;
  }

private:
  int minimum;
  vector<int> stack;
};
#endif

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;
  minStack.pop();
  cout << minStack.top() << endl;
  cout << minStack.getMin() << endl;

  return 0;
}

#endif
