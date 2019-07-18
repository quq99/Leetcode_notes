# Solution for problem 152_Maximum_Product_Subarray

Before you cope with this problem, I recommend you to do the problem 53_Maximum_Subarray first. This problem is really tricky and it shares the similar  solution with problem 53.

Ok, so the brute force solution is simple, just use two loops to track every possible end index. 

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        int global = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = 1;
            for (int j = i; j < nums.size(); j++) {
                tmp = tmp * nums[j];
                global = max(global, tmp);
                
            }
        }
        return global;
    }
};
```

This method has O(N^2) time complexity, so it is very slow. Can we do it faster?

Since we already done problem of "maximum sum of subarray" before, this problem has some similarities. However, the difficulty is how to deal with the negative element.

When we do DP method, we need to know some relationship between dp[i] and dp[i-1]. Here dp[i] are some information about the subarray which ends in index `i`. However, when we have negative element, the relation between dp[i] and dp[i-1] becomes subtle and not easy to figure out.

So, let's see what happened when we encounter a negative element. when we meet a negative number and multiple with it, the maximum product would soon become a minimum product. so how can we get the maximum product of subarray that end in index `i`. Wait, you say the maximum becomes the minimum, how about the minimum? Yes, the minimum becomes the maximum. Specifically, if we use `max_local[i-1]` and `min_local[i-1]` to represent the maximum/minimum product of subarray that start somewhere and end in index `i-1`. Then, if `array[i]` is smaller than 0, what is `max_local[i]`? According to the explaination above, we know

> // if array[i] < 0
>
> max_local[i] = max(min_local[i-1]*array[i], array[i])

So, here we need to keep 2 values: the max cumulative product UP TO current element starting from SOMEWHERE in the past, and the minimum cumuliative product from SOMEWHERE UP TO current element. The rest are similar to problem 53. You can look the code for more information.

The interesting thing about this solution is that it depends not only on a state (the largest product that can be obtained by a sequence ending in the previous number), but two states (the largest and smallest products). A simpler dp problem might just create a `dp[]` and put the maximum value in it(in this case, the largest product). But this solution show us a new way: Our dp array can store more data than just a single value. 