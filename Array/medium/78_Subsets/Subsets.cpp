// Subsets.cpp

#include<vector>

using std::vector;

class Subsets {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> cur;
            helper(nums, 0, cur, res);
            res.push_back({});
            return res;
        }

        void helper(vector<int>&nums, int begin, vector<int>& cur, vector<vector<int>>& res) {
            if (begin < nums.size()) {
                // omit this number
                vector<int> tmp = cur;
                helper(nums, begin+1, cur, res);
                cur = tmp;
                // consider this number
                // 1. done and push to res
                // 2. not done and continue recursive
                cur.push_back(nums[begin]);
                res.push_back(cur);
                helper(nums, begin+1, cur, res);
                cur = tmp;
            }
        }
};
