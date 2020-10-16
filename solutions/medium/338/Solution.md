# Solution 1

To simplify explanations, the following list number from 0 to 15 in 4 bits.

**NOTE: The most right side is a lower bit(bit 0).**

```
 0 = 0 0 0 0 0 0 0 0
 1 = 0 0 0 0 0 0 0 1
 2 = 0 0 0 0 0 0 1 0
 3 = 0 0 0 0 0 0 1 1
 4 = 0 0 0 0 0 1 0 0
 5 = 0 0 0 0 0 1 0 1
 6 = 0 0 0 0 0 1 1 0
 7 = 0 0 0 0 0 1 1 1
 8 = 0 0 0 0 1 0 0 0
 9 = 0 0 0 0 1 0 0 1
10 = 0 0 0 0 1 0 1 0
11 = 0 0 0 0 1 0 1 1
12 = 0 0 0 0 1 1 0 0
13 = 0 0 0 0 1 1 0 1
14 = 0 0 0 0 1 1 1 0
15 = 0 0 0 0 1 1 1 1
```

Then group numbers through the power of 2.

Group 2^0

```
0 = 0 0 0 0 0 0 0 0
```

And

```
1 = 0 0 0 0 0 0 0 1
```

Group 2^1

```
2 = 0 0 0 0 0 0 1 0
3 = 0 0 0 0 0 0 1 1
```

Group 2^2

```
4 = 0 0 0 0 0 1 0 0
5 = 0 0 0 0 0 1 0 1
6 = 0 0 0 0 0 1 1 0
7 = 0 0 0 0 0 1 1 1
```

Group 2^3

```
 8 = 0 0 0 0 1 0 0 0
 9 = 0 0 0 0 1 0 0 1
10 = 0 0 0 0 1 0 1 0
11 = 0 0 0 0 1 0 1 1
12 = 0 0 0 0 1 1 0 0
13 = 0 0 0 0 1 1 0 1
14 = 0 0 0 0 1 1 1 0
15 = 0 0 0 0 1 1 1 1
```

To count the bit quickly, that can refer to previous results and simply plus 1 to get the result of the current number.

For example:

Number 10 is in group 2^3(8), the bits can refer to number 2(10 - 8), so the bits is: 1 + 1 = 2

# Solution 2

The concepts same as solution 1, the reference number is divided by the current number, then check whether the current number is odd or not, if so plus 1.

For example:

Number 7 can refer to the number 3(7 / 2 = 3.5, ignore the decimal point), the bits of number is 2 and the number is odd, so the bits of number would be 3(2 + 1).

In other words, the number 7 is 2 times 3 plus 1 that means the number 7 equals the bits of 3 left shift 1 bit then plus 1.

```
7 = (3 << 1) + 1
```
