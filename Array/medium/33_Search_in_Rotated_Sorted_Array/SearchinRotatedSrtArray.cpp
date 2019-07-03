// SearchinRotatedSrtArray.cpp

#include<vector>
using std::vector;

class SearchinRotatedSrtArray {
    public:
        int search(vector<int>& nums, int target) {
            int len = nums.size();
            if (len == 0) return -1;
            if (len == 1) return target==nums[0]? 0:-1;
            int left = 0;
            int right = len-1;
            while(left <= right) {
                int middle = left + (right-left)/2;
                if (nums[middle] == target) return middle;

                // pay attention to the '==' in the condition
                if (nums[left] <= nums[middle]) {
                    if (target > nums[middle] || target < nums[left]) left = middle+1;
                    else right = middle-1;
                }
                else {
                    // pay attention to the '==' in the condition
                    if (target < nums[middle] || target >= nums[left]) right = middle-1;
                    else left = middle+1;
                }

            }

            return -1;

        }
};
