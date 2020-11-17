#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(vector<int> &nums) { m_nums = nums; }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return m_nums; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> clone(m_nums.begin(), m_nums.end());

    for (int i = 0; i < m_nums.size(); i++) {
      swap(clone[i], clone[i + (rand() % (m_nums.size() - i))]);
    }

    return clone;
  }

private:
  vector<int> m_nums;
};

#ifdef LOCAL_TEST

void dump(vector<int> array) {
  cout << "[";
  for (int i = 0; i < array.size(); i++) {
    if (i > 0)
      cout << ", ";
    cout << array[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  vector<int> array{1, 2, 3};
  Solution s(array);

  dump(s.shuffle());
  dump(s.reset());
  dump(s.shuffle());

  return 0;
}

#endif
