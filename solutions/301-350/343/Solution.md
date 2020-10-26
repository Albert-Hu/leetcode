# Solution

Because the maximum input is not larger than 58, so we can allocate a fixed-length array to store the result of each number we known.

The array is initialized as follows:
- The value of both index 0 and 1 is 0.
- The value of index 2 is 1 that is a known answer to this problem.
- The remainings are set to -1 which meant the unknown answer.

## Split the Number

Assume the input number N, split then N into L and R.
- L means left, start at 1.
- R means right, start at N - 1.
- Run a loop for each time that incress L by 1 and decrease R by 1.
- Stop loop until L greater than R.
- Find the maximum production of L x R.

## Example

Assume that N = 8, L = 1 and R = 7.

- 1 x 7 = 12, 7 = 12 because the maximum production of 7 can be consisted by 3 and 4.
- 2 x 6 = 18, 6 = 9 because the maximum production of 6 can be consisted by 3 and 3.
- 3 x 5 = 18, 5 = 6 because the maximum production of 5 can be consisted by 2 and 3.
- 4 x 4 = 16, the maximum production of 4 still is 4.

**NOTE**: In the above, the 5 can split into 2 and 3 that product is greater than 5, so, if L or R equals the 5 we can replace it into 2 and 3. The 3 although can consist of 2 and 1, but the product is lower than 3, so we don't replace it.
