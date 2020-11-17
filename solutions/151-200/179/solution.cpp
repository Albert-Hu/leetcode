#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> intStrings = toStringArray(nums);

    sort(intStrings.begin(), intStrings.end(),
         [](string a, string b) { return (b + a) < (a + b); });

    return merge(intStrings);
  }

  string merge(vector<string> &intStrings) {
    string str;
    if (intStrings.size() > 0) {
      str = intStrings[0];
    }
    for (int index = 1; index < intStrings.size(); index++) {
      if (str.length() == 1 && str[0] == '0')
        break;
      str += intStrings[index];
    }
    return str;
  }

  vector<string> toStringArray(vector<int> &nums) {
    vector<string> intStrings;
    for (auto n : nums) {
      intStrings.push_back(to_string(n));
    }
    return intStrings;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(0);
  cout << s.largestNumber(nums) << endl;

  nums.clear();
  nums.push_back(10);
  nums.push_back(2);
  cout << s.largestNumber(nums) << endl;

  nums.clear();
  nums.push_back(3);
  nums.push_back(30);
  nums.push_back(34);
  nums.push_back(5);
  nums.push_back(9);
  cout << s.largestNumber(nums) << endl;

  return 0;
}

#endif
