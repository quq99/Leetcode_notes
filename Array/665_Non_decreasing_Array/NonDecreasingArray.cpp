// NonDecreasingArray.cpp

#include<vector>
using std::vector;

class NonDecreasingArray {
    public:
        bool checkPossibility(vector<int>& nums) {
            int count = 0;
            for (int i = 1; i < nums.size() && count <= 1; i++) {
                if (nums[i] < nums[i-1]) {
                    count++;
                    if (i<2 || nums[i-2] <= nums[i]) {
                        nums[i-1] = nums[i];
                    }
                    else {
                        nums[i] = nums[i-1];
                    }
                }
            }
            return count < 2;
        }
};
