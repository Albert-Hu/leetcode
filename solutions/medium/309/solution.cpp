#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = INT32_MIN;
    int bought = 0;
    int sale = 0;
    int sell = 0;

    for (auto p : prices) {
      bought = buy; // bought stock previous day
      buy = max(sell - p, bought); // bought stock current day
      sell = sale; // sell stock previous day
      sale = max(bought + p, sell); // sell stock current day
    }

    return sale;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> prices = {1, 2, 3, 0, 2};

  cout << s.maxProfit(prices) << endl;

  return 0;
}

#endif
