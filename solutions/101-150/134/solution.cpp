#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    return speedup(gas, cost);
  }

private:
  int speedup(vector<int> &gas, vector<int> &cost) {
    if (gas.size() == 0)
      return -1;

    int start = gas.size() - 1;
    int end = 0;
    int remain = gas[start] - cost[start];

    while (start > end) {
      if (remain < 0) {
        --start;
        remain = remain + (gas[start] - cost[start]);
      } else {
        remain = remain + (gas[end] - cost[end]);
        ++end;
      }
    }

    return (remain < 0) ? -1 : start;
  }

  int bruteForce(vector<int> &gas, vector<int> &cost) {
    for (int start = 0; start < gas.size(); start++) {
      if (gas[start] >= cost[start]) {
        int total = gas[start] - cost[start];
        int next = (start + 1) % gas.size();
        while (next != start && total >= 0) {
          total = total + (gas[next] - cost[next]);
          next = (next + 1) % gas.size();
        }
        if (start == next && total >= 0) {
          return start;
        }
      }
    }
    return -1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> gas;
  vector<int> cost;

  gas.push_back(1);
  gas.push_back(2);
  gas.push_back(3);
  gas.push_back(4);
  gas.push_back(5);
  cost.push_back(3);
  cost.push_back(4);
  cost.push_back(5);
  cost.push_back(1);
  cost.push_back(2);
  cout << s.canCompleteCircuit(gas, cost) << endl;

  gas.clear();
  gas.push_back(2);
  gas.push_back(3);
  gas.push_back(4);
  cost.clear();
  cost.push_back(3);
  cost.push_back(4);
  cost.push_back(3);
  cout << s.canCompleteCircuit(gas, cost) << endl;

  return 0;
}

#endif
