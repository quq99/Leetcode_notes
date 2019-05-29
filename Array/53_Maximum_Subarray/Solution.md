# Solution for problem 53_Maximum_Subarray

First, test case. We just use the test case provided by leetcode



```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```



The brute force algorithm is straightforward, we just use two loop and consider all the possible subarray. Specifically, we use i as the start index of the subarray, and j as the end index of the subarray, and use `max_val`to store the result. For each start index i, we increase the index of j to get all the subarray that start from index i. then we use the variable `tmp_sum` to store the sum of subarray start from i and end in j. each time we increase j, we just need to update `tmp_sum` by add up the value in index j. And each time we get a new `tmp_sum`, we need to update the `max_val` by comparing the `max_val` with `tmp_sum`. Note each time after we go through all the possible j for a certain i, we need to reset `tmp_sum` to be 0. The code are as follows:

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            int tmp_sum = 0;
            for (int j=i; j<nums.size(); j++) {
                tmp_sum = tmp_sum + nums[j];
                max_val = max(max_val, tmp_sum);
            }
        }
        return max_val;
    }
};
```



The time complexity of this method is $O(n^2)$. And we are not satisfied with this solution. Since we have to check all the elements in the array, theoretically we can not be faster than $O(n)$. So, we may ask, if we can find out a solution that has time complexity of $O(n)$? How do we find that?