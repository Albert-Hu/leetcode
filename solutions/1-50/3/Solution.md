

# Solution

We make a sliding window to get the length of each substring that is without repeating characters.

## How To Create The Sliding Window?

Here we use two pointers to define the sliding window on the string, then get the substring from that.

The length of the sliding window might be different. The essential is that how to find the beginning and the end.

And the other hand, to record repeated characters, we can use a hash table, but in this case, the character only in ASCII, so we can use an array instead.

The end is started at the beginning and keeps moving to the next until repeated characters occurred.

**Example**

The string is:

```
ABCDABC
```

**Step 1**

The beginning and the end are at index 0.

```
[A] B C D A B C
end: A
```

The table:

- 0, not existed.
- 1, existed.

| A    | B    | C    | D    |
| ---- | ---- | ---- | ---- |
| 1    | 0    | 0    | 0    |

**Step 2**

Move the end to next.

The next is B.

```
A [B] C D A B C
end: B
```

The table:

- 0, not existed.
- 1, existed.

| A    | B    | C    | D    |
| ---- | ---- | ---- | ---- |
| 1    | 1    | 0    | 0    |

**Step 3**

Repeat step 2 until reached the repeated character. 

The repeated character is A.

```
A B C D [A] B C
end: A
```

The table:

- 0, not existed.
- 1, existed.

| A    | B    | C    | D    |
| ---- | ---- | ---- | ---- |
| 1    | 1    | 1    | 1    |

Ultimately the substring is ABCD, and the length is 3.

## How To Move The Sliding Window?

Same as previous how we create the sliding window, the difference is that we start moving the beginning until without repeated character.

**Example**

The string is:

```
ABCDABC
```

The beginning is at index 0, and the end is at index 4.

```
[A] B C D A B C
beginning: A
repeated: A
```

The table:

- 0, not existed.
- 1, existed.

| A    | B    | C    | D    |
| ---- | ---- | ---- | ---- |
| 1    | 1    | 1    | 1    |

**Step 1**

Move the beginning to the next, and remove the repeated character from the table.

```
A [B] C D A B C
beginning: B
repeated: No Repeated
```

The table:

- 0, not existed.
- 1, existed.

| A    | B    | C    | D    |
| ---- | ---- | ---- | ---- |
| 0    | 1    | 1    | 1    |

Now, we get the new beginning of the sliding window. Find the new end of the sliding window to get the length of the next substring.

## Solve it!

Go through the above steps, get every length of the substring that is split by the sliding window, and compare each length to find out the maximum.
