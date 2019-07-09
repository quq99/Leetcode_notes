// BinarySearch.cpp

#include<vector>

using std::vector;

class BinarySearch {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size()-1;
            int first = -1;
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (nums[middle] == target) {
                    if (middle==0 || nums[middle-1]<target) {
                        first = middle;
                        break;
                    }
                    // then nums[middle-1] must equal to target
                    right = middle-1;
                }
                else if (nums[middle] > target) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
            left = 0;
            right = nums.size()-1;
            int second = -1;
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (nums[middle] == target) {
                    if (middle==nums.size()-1 || nums[middle+1]>target) {
                        second = middle;
                        break;
                    }
                    // then nums[middle+1] must equal to target
                    left = middle+1;
                }
                else if (nums[middle] > target) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
            return {first, second};
        }
};
