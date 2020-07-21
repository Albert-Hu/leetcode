#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> results;
    
    for (int i = 1; i <= n; i++) {
      if ((i % 15) == 0) {
        results.push_back("FizzBuzz");
      } else if ((i % 3) == 0) {
        results.push_back("Fizz");
      } else if ((i % 5) == 0) {
        results.push_back("Buzz");
      } else {
        results.push_back(to_string(i));
      }
    }

    return results;
  }
};

#ifdef LOCAL_TEST
void dump(vector<string> results) {
  cout << "[" << endl;
  for (int i = 0; i < results.size(); i++) {
    cout << "  " << results[i];
    if (i < (results.size() - 1)) cout << ",";
    cout << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dump(s.fizzBuzz(15));

  return 0;
}

#endif
