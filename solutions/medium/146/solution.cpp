#include <iostream>
#include <map>
#include <list>

using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) : m_capacity(capacity) {}
  
  int get(int key) {
    int value = -1;
    if (table.count(key) > 0) {
      value = table[key].first;
      keys.splice(keys.begin(), keys, table[key].second);
    }
    return value;
  }
  
  void put(int key, int value) {
    if (table.count(key) > 0) {
      table[key].first = value;
      keys.splice(keys.begin(), keys, table[key].second);
    } else {
      pair<int, list<int>::iterator> p;

      keys.push_front(key);
      p.first = value;
      p.second = keys.begin();
      table[key] = p;

      if (keys.size() > m_capacity) {
        table.erase(keys.back());
        keys.pop_back();
      }
    }
  }

private:
  int m_capacity;
  map<int, pair<int, list<int>::iterator> > table;
  list<int> keys;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;

  return 0;
}

#endif
