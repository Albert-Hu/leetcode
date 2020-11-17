#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    const int n = A.size();
    int count = 0;
    map<long long int, int> twoSum;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        twoSum[A[i] + B[j]]++;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long int sum = -(C[i] + D[j]);
        if (twoSum.count(sum) > 0)
          count += twoSum[sum];
      }
    }

    return count;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> A{1, 2};
  vector<int> B{-2, -1};
  vector<int> C{-1, 2};
  vector<int> D{0, 2};

  cout << s.fourSumCount(A, B, C, D) << endl;

  return 0;
}

#endif
