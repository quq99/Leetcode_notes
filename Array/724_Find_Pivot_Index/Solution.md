# Solution for problem 724_Find_Pivot_Index

First, edge cases, when size of array is 1 or 0, the algorithm should return 0 or -1 respectively.

I may think if O(N) is possible, then we need to sweep the array and record temp informations.

If we have array `A` and the length is `len` We use `A[i, j]` to represent the sum of elements from index i to j. 

So let's see what will happen for general case, then the initial case and end case.

Consider the normal cases in which we know index  `0~(i-1)` is impossible, now we consider index is `i`. because we know pivot index (i-1) is impossible, so  A[0, i-2] are not equal to A[i, len-1]. When we consider index i, we need to know the A[0, i-1] and A[i+1, len-1]. Since we already know A[0, i-2] and A[i, len-1]. So just use the following property

```c
A[0, i-1] = A[0, i-2] + A[i-1]
A[i+1, len-1] = A[i, len-1] - A[i]
```

The computing time is constant.

Next is the initial state, `0` and `A[1, len-1]`.  And end case, `A[0, len-2]` and `0`. Looks good.



Let's go through an example.

```c
Input: 
nums = [1, 7, 3, 6, 5, 6]
Expect Output: 3
```



We use `left_sum` and `right_sum` to represent the sum of elements on the left/right of index i.

First, `i==0`, `left_sum = 0` and `right_sum = 7+3+6+5+6 = 27`

Then `i==1`: `left_sum =0+1` and `right_sum = 27 - 7 = 20`

Then `i==2: ` `left_sum = 1+7=8` and `right_sum = 20 - 3 = 17`

Then `i==3: ` `left_sum = 8+3=11` and `right_sum = 17 - 6 = 11`  Done! return `3`.

So we need to sweep the array twice, the first is to initialize  `left_sum` and `right_sum` , the second is to get pivot index. The time complexity is O(N).