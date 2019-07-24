# Solution for problem 209_Minimum_Size_Subarray_Sum

The O(N) is simple, just maintain a window, and update its size.

The follow is interesting, and the O(NlogN) remind us to use binary search. N remind us to traverse the array.

So, first traverse the array, for each i, look for the proper index such that the sum of subarray is equal or tiny bigger than s. because it is very inconvenient to calculate the sum every time. so we maintain a array that each element is the sum from start to current index in original array. So the sum is the substraction for two element in this array.

For example, 

```c++
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
```

sum array is

```c
[2, 5, 6, 8, 12, 15]
```

First, i is 2, search sums[i]-nums[i]+s=2-2+7=7 in this array, ok it is 8. then len is index of 8 subtract index of 2, which is 4.

Next, i is 5, search 5-3+s = 9 in this array, it is 12, then len is also 4.

Next, i is 6, search 6-1+s = 12 in this array, it is 12, then len is 3.

Next, i is 8, search 8-2+s = 13 in this array, it is 15, then len is 3.

Next, i is 12, search 12-4+s = 15 in this array, it is 15, then len is 2.

Done.

