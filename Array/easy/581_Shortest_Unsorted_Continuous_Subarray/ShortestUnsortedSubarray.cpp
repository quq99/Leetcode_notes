// ShortestUnsortedSubarray.cpp

#include<algorithm>
#include<vector>

using std::max;
using std::min;
using std::vector;

class ShortestUnsortedSubarray {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            const int len = nums.size();
            if (len < 2) {
                return 0;
            }
            // by default, end - start + 1 should be 0, so init end = 2
            int end = -2;
            int start = -1;
            int max_val = INT_MIN;
            int min_val = INT_MAX;
            //iterate from beginning of array
            //find the last element which is smaller than the last seen max from
            //its left side and mark it as end
            for (int i = 0; i < len; i++) {
                max_val = max(max_val, nums[i]);
                if (nums[i] < max_val) {
                    end = i;
                }
            }
            //iterate from end of array
            //find the last element which is bigger than the last seen min from
            //its right side and mark it as begin
            for (int i = len-1; i >= 0; i--) {
                min_val = min(min_val, nums[i]);
                if (nums[i] > min_val) {
                    start = i;
                }
            }

            return end - start + 1;
        }
};
