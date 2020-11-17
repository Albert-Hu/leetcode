#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    if (prices.size() == 1)
      return 0;

    int maximum = 0;
    int minimum = prices[0];

    for (int i = 1; i < prices.size(); i++) {
      maximum = max(maximum, (prices[i] - minimum));
      minimum = min(minimum, prices[i]);
    }

    return maximum;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> prices;

  prices.clear();
  prices.push_back(7);
  prices.push_back(1);
  prices.push_back(5);
  prices.push_back(3);
  prices.push_back(6);
  prices.push_back(4);
  cout << s.maxProfit(prices) << endl;

  prices.clear();
  prices.push_back(7);
  prices.push_back(6);
  prices.push_back(4);
  prices.push_back(3);
  prices.push_back(1);
  cout << s.maxProfit(prices) << endl;

  return 0;
}

#endif
