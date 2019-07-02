# Solution for problem 581_Shortest_Unsorted_Continuous_Subarray

The edge case is when length < 2.

Let's see if we can do the problem in O(N).

So the point of this problem is easy to figure out -- find the end index and start index of the unsorted sub-array.

Once we have end index and start index, the result would be `end - start + 1`. The start index should be initialized as -1, and because if nothing happens(no disorder subarray) the result should be 0, the end index should be initialized as -2.

First, consider the end index(the start index is similar). Because the sorted array is by default in ascending order, we should go through the array from left to right. Suppose at some point in the middle, everything goes right, and the max value we have is `max_val`. So what would happen if there is a disorder subarray? Yes, some element after `max_val` would be smaller than `max_val`, and it is easy to see we need to record the right most one as the end index. Also, it is a dynamic process meaning that we need to update `max_val`  to ensure it is the max value of the elements we have meet and we need to update end index once we have a new `max_val`.

The process to find start index is similar, we need to sweep the array from right to left.

Example, 

```c
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
```

`end` represent end index, `start` represent start index, `nums` represent array, `max_val` represent the max value of the elements we have already meet, `min_val` represent the max value of the elements we have already meet.

Step 1: end index

nums[0] = 2, max_val = 2, end = -2

nums[1] = 6, max_val = 6, end = -2

nums[2] = 4, max_val = 6, end = 2

nums[3] = 8, max_val = 8, end = 2

nums[4] = 10, max_val = 10, end = 2

nums[5] = 9, max_val = 10, end = 5

nums[6] = 15, max_val = 15, end = 5



Step 2: start index

nums[6] = 15, min_val = 15, start = -1

nums[5] = 9, min_val = 9, start = -1

nums[4] = 10, min_val = 9, start = 4

nums[3] = 8, min_val = 8, start = 4

nums[2] = 4, min_val = 4, start = 4

nums[1] = 6, min_val = 4, start = 1

nums[0] = 2, min_val = 2, start = 1



Out = end - start + 1 = 5 - 1 + 1 = 5



Time complexity is O(N).