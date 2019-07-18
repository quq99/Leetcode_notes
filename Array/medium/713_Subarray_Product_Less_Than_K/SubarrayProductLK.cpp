// SubarrayProductLK.cpp

#include<vector>

using std::vector;

class SubarrayProductLK {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if (k <= 1) {
                return 0;
            }
            int left = 0;
            int count = 0;
            int product = 1;
            for (int i = 0; i < nums.size(); i++) {
                product *= nums[i];
                while (product >= k) {
                    product /= nums[left];
                    left++;
                }
                count += i - left + 1;
            }
            return count;
        }
};
