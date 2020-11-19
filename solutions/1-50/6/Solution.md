# Solution 1, Simulation

**Note**: In the following rules, we can return the input string as the answer:

- The length of the input string is 1.
- The number of rows is 1.
- The length of the input string less than or equals the number of rows.



We created a table to simulate the behavior.

**Example:**

```
The input string: PAYPALISHIRING
The number of rows: 3
```

**Step 1**

Put each character into the table:

|  P   |      |  A   |      |  H   |      |  N   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  A   |  P   |  L   |  S   |  I   |  I   |  G   |
|  Y   |      |  I   |      |  R   |      |      |

**Step 2**

Go through the table line by line, remove the space character on the line.
It would look like:

|  P   |  A   |  H   |  N   |      |      |      |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  A   |  P   |  L   |  S   |  I   |  I   |  G   |
|  Y   |  I   |  R   |      |      |      |      |

**Step 3**

Finally, concatenate all of the lines to get the answer: **PAHNAPLSIIGYIR**



# Solution 2, Index Jumping

Refer to solution 1, using the index instead, and find the distance between two characters in the same row. Then, we get every character via jump the index.

**Example:**

```
The input string: PAYPALISHIRING
The number of rows: 4
```

**Step 1**

Put each character into the table:

|  P   |      |      |  I   |      |      |  N   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  A   |      |  L   |  S   |      |  I   |  G   |
|  Y   |  A   |      |  H   |  R   |      |      |
|  P   |      |      |  I   |      |      |      |

**Step 2**

Find the **distance** between the characters on each row:

- In the 1st row, the distance is 6.
- In the 2nd row, the order of distances is 2 and 4.
- In the 2nd row, the order of distances is 4 and 2.
- In the last row, the distance is 6.

Get each character by jumping the index column by column on each row.

**The Formulas:**

```
d1: 1st distance
d2: 2nd distance
r: number of rows
i: index of row

d1 = (2r - 2) - (2i mod (2r - 2))
d2 = (2r - 2) - (((2r - 2) - 2i) mod (2r - 2))
```

To simplify the code, both the first row and the last row which has two same distance values(two 6s).

**Step 3**

Convert the character using the index instead:

|  0   |      |      |  6   |      |      |  12  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |      |  5   |  7   |      |  11  |  13  |
|  2   |  4   |      |  8   |  10  |      |      |
|  3   |      |      |  9   |      |      |      |

Go through every row to collect the characters via index jumping.

- In the 1st, the indices are [0, 6, 12].
- In the 2nd, the indices are [1, 5, 7, 11, 13];
- In the 3rd, the indices are [2, 4, 8, 10].
- In the last, the indices are [3, 9].

The answer is **PINALSIGYAHRPI**.