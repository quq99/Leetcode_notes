// MaxProductSubarray.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::max;
using std::min;
using std::swap;

class MaxProductSubarray {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 1) {
                return nums[0];
            }
            int global = nums[0];
            // local_max/local_min stores the max/min product of
            // subarray that ends with the current number nums[i]
            int local_min = nums[0];
            int local_max = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < 0) {
                    swap(local_min, local_max);
                }
                local_max = max(local_max*nums[i], nums[i]);
                local_min = min(local_min*nums[i], nums[i]);
                global = max(global, local_max);
            }
            return global;
        }
};
