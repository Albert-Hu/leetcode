#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#ifdef LOCAL_TEST
class NestedInteger {
public:
  NestedInteger(int val)
    : m_isInteger(true)
    , m_value(val) {}
  
  NestedInteger(vector<NestedInteger> list)
    : m_isInteger(false)
    , m_value(0) {
      m_list = list;
    }

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() { return m_isInteger; }

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() { return m_value; }

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() { return m_list; }

private:
  bool m_isInteger;
  int m_value;
  vector<NestedInteger> m_list;
};
#endif

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    function<void(const vector<NestedInteger>&)> unpack = [&] (const vector<NestedInteger> &l) {
      for (auto element : l) {
        if (element.isInteger()) {
          list.push(element.getInteger());
        } else {
          unpack(element.getList());
        }
      }
    };
    unpack(nestedList);
  }
  
  int next() {
    int i = list.front();
    list.pop();
    return i;
  }
  
  bool hasNext() {
    return !list.empty();
  }
private:
  int start;
  queue<int> list;
};

#ifdef LOCAL_TEST

void dump(NestedIterator &iterator) {
  bool showComma = false;
  cout << "[";
  while (iterator.hasNext()) {
    if (showComma) cout << ", ";
    else showComma = true;
    cout << iterator.next();
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  vector<NestedInteger> list {
    NestedInteger(
      vector<NestedInteger> {
        NestedInteger(1),
        NestedInteger(1)}),
    NestedInteger(2),
    NestedInteger(
      vector<NestedInteger> {
        NestedInteger(1),
        NestedInteger(1)})
  };
  NestedIterator iterator(list);

  dump(iterator);

  return 0;
}

#endif
