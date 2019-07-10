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

Since we need to store some information about the array, and  we may need to update status of some useful variables. We can think about using DP methods. 

At first, I think the sub problem should look like: `maxSubArray(int A[], int i, int j)`. However, if we define the format of the sub problem in this way, it's hard to find the connection from the sub problem to the original problem. It is difficult for me to manage the solutions of the sub problems to get the solution of the original one.

So I change the format of the sub problem into something like: `maxSubArray(int A[], int i)`, which means the maxSubArray for A[0:i ] which must has A[i] as the end element. The idea behind this is instead of dealing with two variables at the same time, we solve one variable and treat it as a sub problem of the global problem. Now we have to keep track of each solution of the sub problem to update the global optimal value. However, now the connect between the sub problem & the original one becomes clearer:



```c
maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) + A[i] : 0 + A[i]; 
```

Each time when we update the maxSubArray, we compare it with the global max sum value and update it. Finally we will get the optimal sum of subarray for the whole array.

The time complexity is $O(N)$.



Then, the divide and conquer method is straightforward. In the devide and conquer method, we will devide the array into two parts and solve the problem recursively. Here is one problem, how do we handle the subarray that contains both left part and right part. One reasonable solution would be get the middle element that we use to devide the array into two part, and expand the array from that point to left and right. Done!

Suppose the array A[i, j] and the middle index m. We consider the result of A[i, m-1] , A[m+1, j] and consider expand from the element A[m] to left and to right, then get the max array A[crossleft, crossright]. At last, return the maximum of A[i, m-1] , A[m+1, j], and A[crossleft, crossright]. Be careful about the index when you calculate A[crossleft, crossright]. 

```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    int helper(vector<int> &nums, int left, int right) {
        if (left > right) {
            return INT_MIN;
        }
        int middle = left + (right - left) / 2;
        int leftmax = helper(nums, left, middle-1);
        int rightmax = helper(nums, middle+1, right);
        // now calculate A[left, right] that cross the element A[middle].
        int crossleft = nums[middle];
        
        for (int i = middle-1, tmp = crossleft; i>=left; i--) {
            tmp += nums[i];
            crossleft = max(tmp, crossleft);
        }
        int crossmax = crossleft;
        for (int i = middle+1, tmp = crossleft; i<=right; i++) {
            tmp += nums[i];
            crossmax = max(tmp, crossmax);
        }
        
        return max(max(leftmax, rightmax), crossmax);
    }
};
```



Now we can compute the running time complexity.
$$
T(N) = 2T(N/2) + O(N)
$$


This recurrence has time complexity of $O(NlogN)$.