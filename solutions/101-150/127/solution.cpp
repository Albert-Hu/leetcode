#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //return graph_bfs(beginWord, endWord, wordList);
    return speedup_bfs(beginWord, endWord, wordList);
  }
private:
  int speedup_bfs(string beginWord, string endWord, vector<string>& wordList) {
    int length = 0;
    unordered_set<string> path;
    unordered_set<string> words(wordList.begin(), wordList.end());

    path.insert(beginWord);
    while (!path.empty()) {
      unordered_set<string> next;
      
      length += 1;
      if (path.count(endWord) > 0) {
        return length;
      }
      if (!words.empty()) {
        for (auto p : path) {
          for (int i = 0; i < p.length(); ++i) {
            char ori = p[i];
            for (char c = 'a'; c <= 'z'; ++c) {
              p[i] = c;
              if (words.count(p) > 0) {
                words.erase(p);
                next.insert(p);
              }
            }
            p[i] = ori;
          }
        }
      }
      path = next;
    }

    return 0;
  }

  int graph_bfs(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, unordered_set<string> > path;
    unordered_set<string> visited;

    function<int(int,unordered_set<string>&)> bfs = [&](int n, unordered_set<string> &connections) {
      if (connections.find(endWord) != connections.end())
        return n;

      unordered_set<string> next;
      for (auto c : connections) {
        for (auto word : path[c]) {
          if (visited.find(word) == visited.end()) {
            visited.insert(word);
            next.insert(word);
          }
        }
      }
      return (next.size() > 0) ? bfs(n + 1, next) : 0;
    };

    for (int i = 0; i < wordList.size(); ++i) {
      if (canConnect(beginWord, wordList[i])) {
        path[beginWord].insert(wordList[i]);
      }
      for (int j = 0; j < wordList.size(); ++j) {
        if (i == j) continue;
        if (canConnect(wordList[i], wordList[j])) {
          path[wordList[i]].insert(wordList[j]);
        }
      }
    }
    return bfs(2, path[beginWord]);
  }

  bool canConnect(string &a, string &b) {
    if (a.length() != b.length()) {
      return false;
    }
    int count = 0;
    for (int i = 0; i < a.length() && (count < 2); ++i) {
      if (a[i] != b[i]) {
        count++;
      }
    }
    return (count == 1);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  string beginWord;
  string endWord;
  vector<string> wordList;

  beginWord = "hit";
  endWord = "cog";
  wordList.push_back("hot");
  wordList.push_back("dot");
  wordList.push_back("dog");
  wordList.push_back("lot");
  wordList.push_back("log");
  wordList.push_back("cog");
  cout << s.ladderLength(beginWord, endWord, wordList) << endl;

  beginWord = "hit";
  endWord = "cog";
  wordList.clear();
  wordList.push_back("hot");
  wordList.push_back("dot");
  wordList.push_back("dog");
  wordList.push_back("lot");
  wordList.push_back("log");
  cout << s.ladderLength(beginWord, endWord, wordList) << endl;

  beginWord = "hit";
  endWord = "cog";
  wordList.clear();
  wordList.push_back("hot");
  wordList.push_back("hit");
  wordList.push_back("cog");
  wordList.push_back("dot");
  wordList.push_back("dog");
  cout << s.ladderLength(beginWord, endWord, wordList) << endl;

  return 0;
}

#endif
