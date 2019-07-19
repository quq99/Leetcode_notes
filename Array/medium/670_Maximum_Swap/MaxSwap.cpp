// MaxSwap.cpp

#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class MaxSwap {
    public:
        int maximumSwap(int num) {
            string nums = to_string(num);
            int max_v = nums.size()-1; // max number position
            int right = -1;
            int left = -1;
            // traverse from right to left
            for (int i = nums.size()-1; i>=0; i--) {
                if (nums[i] > nums[max_v]) {
                    max_v = i;
                    continue;
                }
                // update the leftmost number that smaller than maximum number
                if (i<nums.size()-1 && nums[i] < nums[max_v]) {
                    left = i;
                    right = max_v;
                }
            }
            swap(nums[left], nums[right]);
            return stoi(nums);
        }

};
