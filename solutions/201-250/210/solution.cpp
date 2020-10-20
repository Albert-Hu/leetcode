#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites) {
    vector<int> result;
    map<int, set<int> > graph;

    for (auto p : prerequisites) {
      graph[p[0]].insert(p[1]);
    }

    if (isValid(graph)) {
      topologicalSort(graph, result);
      for (int course = 0; course < numCourses; course++) {
        if (graph.count(course) == 0) {
          result.insert(result.begin(), course);
        }
      }
    }

    return result;
  }

  void topologicalSort(map<int, set<int> > &graph, vector<int> &result) {
    map<int, int> references;

    for (auto g : graph) {
      if (references.count(g.first) == 0) {
        references[g.first] = 0;
      }
      for (auto course : g.second) {
        if (references.count(course) == 0) {
          references[course] = 0;
        }
        references[course]++;
      }
    }

    while (references.size() > 0) {
      vector<int> beginnings;
      for (auto ref : references) {
        if (ref.second == 0) {
          beginnings.push_back(ref.first);
        }
      }
      for (auto b : beginnings) {
        result.insert(result.begin(), b);
        references.erase(b);
        for (auto course : graph[b]) {
          references[course]--;
        }
      }
    }
  }

  bool isValid(map<int, set<int> > &graph) {
    set<int> visited;
    set<int> valid;

    for (auto g : graph) {
      if (valid.count(g.first) == 0) {
        if (!isValid(graph, g.first, valid, visited)) {
          return false;
        }
      }
    }

    return true;;
  }

  bool isValid(map<int, set<int> > &graph, int beginning, set<int> &valid, set<int> &visited) {
    if (visited.count(beginning) > 0)
      return false;
    
    visited.insert(beginning);
    for (auto next : graph[beginning]) {
      if (valid.count(next) > 0)
        continue;
      if (!isValid(graph, next, valid, visited)) {
        return false;
      }
    }
    visited.erase(beginning);

    valid.insert(beginning);
    
    return true;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> result) {
  cout << "[";
  for (int i = 0; i < result.size(); i++) {
    if (i > 0) cout << ", ";
    cout << result[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > prerequisites;

  dump(s.findOrder(2, prerequisites));

  prerequisites.clear();
  prerequisites.push_back(vector<int>{1,0});
  dump(s.findOrder(2, prerequisites));

  prerequisites.clear();
  prerequisites.push_back(vector<int>{1,0});
  prerequisites.push_back(vector<int>{2,0});
  prerequisites.push_back(vector<int>{3,1});
  prerequisites.push_back(vector<int>{3,2});
  dump(s.findOrder(4, prerequisites));

  return 0;
}

#endif
