// MaxSubarray.cpp

#include<vector>

using namespace std;

class MaxSubarray {
    public:
        int maxSubArray(vector<int>& nums) {
            int CurSum = nums[0];
            int MaxSum = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                // maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ?
                //                     maxSubArray(A, i - 1) + A[i] : 0 + A[i];
                CurSum += nums[i];
                if (CurSum < nums[i]) {
                    CurSum = nums[i];
                }
                // update global optimal
                if (CurSum > MaxSum) {
                    MaxSum = CurSum;
                }
            }
            return MaxSum;
        }
};
