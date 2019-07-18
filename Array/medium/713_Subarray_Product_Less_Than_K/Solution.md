# Solution for problem 713_Subarray_Product_Less_Than_K

First, the edge case is when k equals 0 and 1, we should return 0.

The brute force way, of course, is to use two for loop to check each possible subarray.

Any better way?

How about sliding window, because it says "less than something" and the subarray should be continues elements. And because array has two variables(start and end index), we prefer to fix one at each step. Let's fix the end index, and each time move one step for the end index. So the next problem is to deal with start index, it is not hard to figure out that we just move the start index until the product is less than K. During the traverse, we maintain a tmp variable to indicate the product of the subarray.

For example, 

```c
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
```

we use a for loop to traverse the array, and `i` is the end index.

Initially, `i` is 0, `left` index(start index of subarray) is 0, and product is 1. `Count` is the output

First, i == 0, left is 0, product is 10, ok, count = 1,

Next, i==1, left is 0, product is 50, ok, add [5] and [10,5] so the number is just `i-left+1`, count = 3 

Next, i==2, left is 0, product is 100, so we need to move left index, move one step is ok, left is 1 and product is 100/10=10, add [2] and [5,2], add i-left+1=2, so count is 5

Next, i==3, left is 1, product is 60, ok,  add i-left+1=3, so count is 8.