#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    map<int, set<int>> graph;
    set<int> visited;
    set<int> courses;
    function<bool(int)> hasCircle = [&](int course) {
      if (visited.count(course) > 0)
        return true;

      vector<int> next(graph[course].begin(), graph[course].end());
      visited.insert(course);
      for (auto n : next) {
        if (hasCircle(n)) {
          return true;
        }
      }
      visited.erase(course);
      courses.erase(course);
      return false;
    };

    for (auto p : prerequisites) {
      graph[p[0]].insert(p[1]);
      courses.insert(p[0]);
    }

    while (courses.size() > 0) {
      int c = *(courses.begin());
      if (hasCircle(c)) {
        return false;
      }
    }

    return true;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> prerequisites;

  prerequisites.push_back(vector<int>{1, 0});
  cout << (s.canFinish(2, prerequisites) ? "true" : "false") << endl;

  prerequisites.clear();
  prerequisites.push_back(vector<int>{0, 1});
  cout << (s.canFinish(2, prerequisites) ? "true" : "false") << endl;

  prerequisites.clear();
  prerequisites.push_back(vector<int>{1, 0});
  prerequisites.push_back(vector<int>{0, 1});
  cout << (s.canFinish(2, prerequisites) ? "true" : "false") << endl;

  prerequisites.clear();
  prerequisites.push_back(vector<int>{2, 0});
  prerequisites.push_back(vector<int>{2, 1});
  cout << (s.canFinish(2, prerequisites) ? "true" : "false") << endl;

  return 0;
}

#endif
