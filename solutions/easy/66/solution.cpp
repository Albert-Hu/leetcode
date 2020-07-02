#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int sum = 0, carry = 1;
    vector<int> array;

    for (int i = digits.size() - 1; i > -1; i--) {
      sum = digits[i] + carry;
      carry = sum / 10;
      array.insert(array.begin(), (sum % 10));
    }
    if (carry > 0) {
      array.insert(array.begin(), 1);
    }

    return array;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> array) {
  cout << "[";
  for (int i = 0; i < array.size(); i++) {
    if (i > 0) cout << ", ";
    cout << array[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> digits;

  digits.push_back(1);
  digits.push_back(2);
  digits.push_back(3);
  dump(s.plusOne(digits));

  digits.clear();
  digits.push_back(4);
  digits.push_back(3);
  digits.push_back(2);
  digits.push_back(1);
  dump(s.plusOne(digits));


  return 0;
}

#endif
