# Solution 1, Hash Table

Use HashTable to record the index of each number and calculate the difference between the target and current number, then check whether the difference is in HashTable or not, if so, the answer is found.

## Example

Target = 9, Numbers = [2, 7, 11, 15], Table = []

- Map 2 to index 0, Table[2] = 0
- Map 7 to index 1, Table[7] = 1
- Map 11 to index 2, Table[11] = 2
- Map 15 to index 3, Table[15] = 3

All of the differences:

- The index 0, 9 - 2 = 7
- The index 1, 9 - 7 = 2
- The index 2, 9 - 11 = -2
- The index 3, 9 - 15 = -6

We can found the answer is [0, 1].

# Solution 2, Sort and Binary Search

We need to allocate a new array to store the index of numbers, then sort the indices via number, and use binary search to find out the answer.

## Example

Target = 9, Numbers = [7, 11, 2, 15].

- Map the numbers [7, 11, 2, 15] to an index array [0, 1, 2, 3].
- Sort the index array.
- The sorted index array is [2, 0, 1, 3] that map to the sorted numbers [2, 7, 11, 15].
- Go through every element of the index array to get the difference from the target.
- Use the binary search to look for the difference in the index array.
- For example, the index 2 map to number 2, and the number we need to find is 7, so we search its index in the index array.

The source code:

```
vector<int> Solution::twoSum(vector<int>& nums, int target) {
  vector<int> answer;
  vector<int> indices;

  for (unsigned int i = 0; i < nums.size(); i++) {
    indices.push_back(i);
  }

  sort(indices.begin(), indices.end(), [&](int a, int b) {
    /* map the index to the number */
    return nums[a] < nums[b];
  });

  for (unsigned int i = 0; i < indices.size(); i++) {
    int n = target - nums[indices[i]];
    auto m = lower_bound(indices.begin() + i + 1, indices.end(), n, [&](int index, int value) {
      /* map the index to the number */
      return nums[index] < value;
    });

    if (m != indices.end()) {
      if (nums[indices[m - indices.begin()]] == n) {
        answer.push_back(indices[i]);
        answer.push_back(indices[m - indices.begin()]);
        break;
      }
    }
  }

  return answer;
}
```
