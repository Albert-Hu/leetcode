#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  Solution() : minimalAmount(INT32_MAX) {}

  int coinChange(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    search(coins, 0, 0, amount);
    return (minimalAmount == INT32_MAX) ? -1 : minimalAmount;
  }

  void search(vector<int> &coins, int index, int count, int amount) {
    if (index < coins.size()) {
      int c = coins[index];
      int number = amount / c;
      int money = c * number;

      if ((number + count) <= minimalAmount) {
        while (number > -1) {
          if (money == amount) {
            minimalAmount = min(minimalAmount, (number + count));
          } else {
            search(coins, index + 1, count + number, amount - money);
          }
          number--;
          money -= c;
        }
      }
    }
  }

private:
  int minimalAmount;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;
  vector<int> coins;

  s = new Solution;
  coins.clear();
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(5);
  cout << s->coinChange(coins, 11) << endl;

  s = new Solution;
  coins.clear();
  coins.push_back(2);
  cout << s->coinChange(coins, 3) << endl;

  return 0;
}

#endif
