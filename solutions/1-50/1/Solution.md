# Solution

Use HashTable to record the index of each number and calculate the difference between the target and current number, then check whether the difference is in HashTable or not, if so, the answer is found.

# Example

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
