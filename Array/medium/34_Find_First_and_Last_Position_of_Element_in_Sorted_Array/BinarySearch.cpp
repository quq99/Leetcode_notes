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

class BinarySearch2 {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if (nums.size()==0) return {-1,-1};
            if (nums.size()==1) {
                if (nums[0]==target) return {0,0};
                else return {-1,-1};
            }
            int l = 0;
            int r = nums.size()-1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] < target) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
            int first = nums[l]==target ? l : -1;
            l = 0;
            r = nums.size()-1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] <= target) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
            int second = -1;
            if (nums[l]==target) second = l;
            else if (l!=0 && nums[l-1]==target) second = l-1;
            return {first, second};

        }
};
