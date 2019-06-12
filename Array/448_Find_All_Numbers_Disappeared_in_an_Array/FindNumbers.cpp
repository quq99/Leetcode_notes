// FindNumbers.cpp

#include<vector>

using std::vector;

class FindNumbers {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> res = {};
            int val = 0;
            // make the corresponding position to be negtive.
            for (int i=0; i<nums.size(); i++) {
                val = abs(nums[i]) - 1;
                nums[val] = nums[val]>0 ? -nums[val] : nums[val];
            }
            for (int i=0; i<nums.size(); i++) {
                if (nums[i]>0) {
                    res.push_back(i+1);
                }
            }
            return res;
        }
};
