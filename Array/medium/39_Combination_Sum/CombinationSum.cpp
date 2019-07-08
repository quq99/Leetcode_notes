// CombinationSum.cpp

#include<vector>

using std::vector;

class CombinationSum {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> cur = {};
            sort(candidates.begin(), candidates.end());
            helper(res, candidates, cur, target, 0);
            return res;
        }

        void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int remain, int begin) {
            if (remain == 0) {
                res.push_back(cur);
                return;
            }

            // start from begin position can avoid duplicate results.
            for (int i = begin; i < nums.size() && remain>=nums[i]; i++) {
                cur.push_back(nums[i]);
                helper(res, nums, cur, remain-nums[i], i);
                cur.pop_back();
            }

        }
};
