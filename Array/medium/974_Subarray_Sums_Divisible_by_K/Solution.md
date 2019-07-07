# Solution for problem 974_Subarray_Sums_Divisible_by_K

This problem is very similar to the problem 560_Subarray_Sum_Equals_K.

And the idea is also very similar. the only difference is now we are supposed to check whether the subarray sum can be divided by K.

Follow the procedure of problem 560, now we have 

if sum[0, i] % K == sum[0, j] % K, sum[i + 1, j] is divisible by by K.
So for current index j, we need to find out how many index i (i < j) exit that has the same mod of K.
Now it easy to come up with HashMap <mod, frequency>

Then a tiny problem is how to deal with the negative sum. For example, if the sum is -1 and K is 5. -1 % 5 is -1, so we need to convert it to 4 by add 5(K is 5 in this example).

For more info, check the Solution.md file in 560_Subarray_Sum_Equals_K.