// ThreeSum.cpp

#include<vector>
#include<algorithm>
using std::sort;
using std::vector;

class Threesum {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            int len = nums.size();
            if (len < 3) return {};

            sort(nums.begin(), nums.end());
            for (int i = 0; i < len-2; i++) {
                // if current number > 0, the right side add up must
                // be bigger than 0, so we can just stop the loop and
                // return the result.
                if (nums[i] > 0) {
                    return res;
                }
                int remain = -nums[i];
                int left = i+1;
                int right = len-1;
                while (left < right) {
                    if (nums[left]+nums[right] < remain) {
                        left++;
                    }
                    else if (nums[left]+nums[right] > remain) {
                        right--;
                    }
                    else {
                        res.push_back({nums[i], nums[left], nums[right]});
                        // jump duplicate left and right
                        int tmp1 = nums[left];
                        while(left<right && nums[left]==tmp1) left++;
                        int tmp2 = nums[right];
                        while(left<right && nums[right]==tmp2) right--;
                    }
                }
                // jump duplicate i
                while (i < len-1 && nums[i+1]==nums[i]) i++;

            }

            return res;
        }
};
