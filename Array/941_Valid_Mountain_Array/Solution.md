# Solution for problem 941_Valid_Mountain_Array

First come up with test cases. There are three kind of cases.

1. Size of array smaller than 3, return false
2. Decrease from second element, return false
3. The array is increase all the way, return false
4. Right cases



Once we have this, the algorithm is simple. First find out the first decrease number. If it is the second number or if it does not exist, then return false. Second, from that number to the end of array, check if the rest of array is decreasing.

For example

```c
Input: [0,3,2,1]
Output: true
```

First find the decrease number appears first, which is 2. Check the position of 2. It is not the case 2 or case 3.

Then from 2, check if it is smaller than the previous number, so 2 is smaller than 3, right; next 1 is smaller than 2, right, reach the end of array. return true.