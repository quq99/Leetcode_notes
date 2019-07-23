# Solution for problem 410_Split_Array_Largest_Sum

The following content is copied from [there](<https://leetcode.com/problems/split-array-largest-sum/discuss/89817/Clear-Explanation%3A-8ms-Binary-Search-Java>)



1. The answer is between maximum value of input array numbers and sum of those numbers.
2. Use binary search to approach the correct answer. We have `l = max number of array; r = sum of all numbers in the array;`Every time we do `mid = (l + r) / 2;`
3. Use greedy to narrow down left and right boundaries in binary search.
   3.1 Cut the array from left.
   3.2 Try our best to make sure that the sum of numbers between each two cuts (inclusive) is large enough but still less than `mid`.
   3.3 We'll end up with two results: either we can divide the array into more than m subarrays or we cannot.
   **If we can**, it means that the `mid` value we pick is too small because we've already tried our best to make sure each part holds as many non-negative numbers as we can but we still have numbers left. So, it is impossible to cut the array into m parts and make sure each parts is no larger than `mid`. We should increase m. This leads to `l = mid + 1;`
   **If we can't**, it is either we successfully divide the array into m parts and the sum of each part is less than `mid`, or we used up all numbers before we reach m. Both of them mean that we should lower `mid` because we need to find the minimum one. This leads to `r = mid - 1;`



So, one more question:

```
Why we will return l as our final result?`
`Is it guaranteed to be a valid answer?
```



First, I think it's important to know why we choose `(l <= r)` as the condition in our while loop. It's because we can't decide if the `mid` is our expectation. So that we need to check it when `l` meets `r`.



Secondly, let's talk about the case when we break the loop. It will always be the situation `l > r`. You may want to ask yourself, how did we came to this case? It must be the case `r - l = 1` and then `valid` is `true` or the case when `l == r`. Let's talk about the former one first.



1. `r - l = 1` and `valid` function returns `true`



Think about the case when `l = 5, r =6`. Now, `mid = 5`, right? If `valid` returns `true`, `r` should be `mid - 1`, which is `4`.



If `valid` returns `true`, it means we may find a possible solution for splitting the array. Probably you may ask how do we know `l` is the right answer. It could be the case that `we used up all numbers before we reach m` so that valid returns `true`.



Please keep in mind when `l = 4`, the `valid` function should return `false` (we find more than `m` parts). That's how we get `l = 5`. But with `l == mid == 5`, we find a valid solution. It's guaranteed to be the minimized largest sum.



1. `l == r`



Probably you have noticed that how we came to this situation. It **must** be the case `r - l = 1` and `valid` function returns `false`. So the second situation come from the first one.



We could still use the example when `l = 5, r = 6, mid = (5 + 6) / 2 = 5`. You know `valid` returns `false` , so now `l = 5 + 1 = 6, r = 6, mid = 6`. Also, it's important to know `7` is a possible answer since this is how we get `r = 6 (r = mid - 1)`.



If `valid` returns `true`, so now `l = 6` must be the right answer since we we will find more than `m` parts if the largest sum is `5`



If `valid` returns `false`, which means we will find more than `m` parts if sun is `6`. But we already know we could find a valid solution when sum is `7`, and now `l = mid + 1 = 6 + 1 = 7`.