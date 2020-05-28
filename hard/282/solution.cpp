#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> addOperators(string num, int target) {
      vector<string> results;
      return results;
  }
};

#ifdef LOCAL_TEST

void dump(vector<string> answer) {
  cout << "[";
  for (int i = 0; i < answer.size(); ++i) {
    if (i > 0) {
      cout << ", ";
    }
    cout << answer[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dump(s.addOperators("232", 8));
  dump(s.addOperators("3456237490", 9191));
  
  return 0;
}

#endif
