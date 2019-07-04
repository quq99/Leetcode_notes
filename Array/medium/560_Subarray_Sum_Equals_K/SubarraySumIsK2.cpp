// SubarraySumIsK2.cpp

#include<vector>
using std::vector;

class SubarraySumIsK2 {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int len = nums.size();
            if (len == 1) return nums[0]==k;

            int sum = 0;
            int count = 0;
            for (int i = 0; i < len; i++) {
                sum = 0;
                for (int j = i; j < len; j++) {
                    sum += nums[j]; // sum from index i to j
                    if (sum == k)
                        count++;
                }
            }
            return count;
        }
};
