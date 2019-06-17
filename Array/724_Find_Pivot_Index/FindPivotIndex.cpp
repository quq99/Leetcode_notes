// FindPivotIndex.cpp

#include<vector>
using std::vector;

class FindPivotIndex {
    public:
        int pivotIndex(vector<int>& nums) {
            // edge cases
            int len = nums.size();
            if (len == 1) {
                return 0;
            }
            if (len < 1) {
                return -1;
            }
            // init left_sum = 0
            // init right_sum = sum of elements from index 1 to end
            int left_sum = 0;
            int right_sum = 0;
            for (int i = 1; i < len; i++) {
                right_sum += nums[i];
            }
            // check all possible pivot index
            for (int i = 0; i < len; i++) {

                if (left_sum == right_sum) {
                    return i;
                }
                // update left_sum and right_sum
                // for next possible pivot index
                if (i<len-1) {
                    left_sum += nums[i];
                    right_sum -= nums[i+1];
                }
            }
            return -1;
        }
};
