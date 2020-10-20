#include <iostream>
using namespace std;

class Trie {
public:
  Trie() : isEnd(false) {
    for (int i = 0; i < 26; i++) {
      next[i] = nullptr;
    }
  }
  
  void insert(string word) {
    int index = static_cast<int>(word[0] - 'a');

    if (next[index] == nullptr) {
      next[index] = new Trie();
    }

    if (word.length() == 1) {
      next[index]->isEnd = true;
    } else {
      next[index]->insert(word.substr(1));
    }
  }
  
  bool search(string word) {
    int index = static_cast<int>(word[0] - 'a');

    if (next[index] == nullptr) {
      return false;
    }

    if (word.length() == 1) {
      return next[index]->isEnd;
    }

    return next[index]->search(word.substr(1));
  }

  bool startsWith(string prefix) {
    int index = static_cast<int>(prefix[0] - 'a');

    if (next[index] == nullptr) {
      return false;
    }

    if (prefix.length() == 1) {
      return true;
    }

    return next[index]->startsWith(prefix.substr(1));
  }

private:
  bool isEnd;
  Trie *next[26];
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Trie *obj = new Trie();

  obj->insert("apple");
  cout << (obj->search("apple") ? "true" : "false") << endl;
  cout << (obj->search("app") ? "true" : "false") << endl;
  cout << (obj->startsWith("app") ? "true" : "false") << endl;
  obj->insert("app");
  cout << (obj->search("app") ? "true" : "false") << endl;

  return 0;
}

#endif
