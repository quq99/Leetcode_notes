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

class SearchinRotatedSrtArray2 {
    public:
        int search(vector<int>& nums, int target) {
            int len = nums.size();
            if (len==0) return -1;
            if (len==1) return nums[0]==target? 0 : -1;
            int l = 0;
            int r = len - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] > target) {
                    // mid position 1
                    if (nums[mid] < nums[r]) r = mid-1;
                    // mid position 2, two cases
                    else if (target >= nums[l]) r = mid - 1;
                    else l = mid + 1;
                }
                else {
                    // mid position 1
                    if (nums[mid] > nums[r]) l = mid + 1;
                    // mid position 2, two cases
                    else if (target <= nums[r]) l = mid + 1;
                    else r = mid - 1;
                }
            }


            return -1;
        }
};
