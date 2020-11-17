#include <iostream>
#include <map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() : size(0) {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (index.count(val) > 0)
      return false;
    if (size < array.size())
      array[size] = val;
    else
      array.push_back(val);
    index[val] = size;
    size++;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (index.count(val) == 0)
      return false;
    int i = index[val];
    array[i] = array[--size];
    index[array[i]] = i;
    index.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return array[rand() % size]; }

private:
  int size;
  vector<int> array;
  map<int, int> index;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  RandomizedSet *obj = new RandomizedSet();

  cout << (obj->insert(1) ? "true" : "false") << endl;
  cout << (obj->remove(2) ? "true" : "false") << endl;
  cout << (obj->insert(2) ? "true" : "false") << endl;
  cout << obj->getRandom() << endl;
  cout << (obj->remove(1) ? "true" : "false") << endl;
  cout << (obj->insert(2) ? "true" : "false") << endl;
  cout << obj->getRandom() << endl;

  return 0;
}

#endif
