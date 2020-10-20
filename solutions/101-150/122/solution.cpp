#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    
    for (int i = 1; i < prices.size(); i++) {
      if ((prices[i] - prices[i - 1]) > 0) {
        profit += (prices[i] - prices[i - 1]);
      }
    }

    return profit;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;
  vector<int> prices;

  s = new Solution;
  prices.clear();
  prices.push_back(7);
  prices.push_back(1);
  prices.push_back(5);
  prices.push_back(3);
  prices.push_back(6);
  prices.push_back(4);
  cout << s->maxProfit(prices) << endl;

  s = new Solution;
  prices.clear();
  prices.push_back(1);
  prices.push_back(2);
  prices.push_back(3);
  prices.push_back(4);
  prices.push_back(5);
  cout << s->maxProfit(prices) << endl;

  s = new Solution;
  prices.clear();
  prices.push_back(7);
  prices.push_back(6);
  prices.push_back(4);
  prices.push_back(3);
  prices.push_back(1);
  cout << s->maxProfit(prices) << endl;

  return 0;
}

#endif
