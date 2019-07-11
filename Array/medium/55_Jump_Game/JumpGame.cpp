// JumpGame.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class JumpGame {
    public:
        bool canJump(vector<int>& nums) {
            int len = nums.size();
            if (len < 2) return true;

            int remain = 0;
            for (int i = 0; i < len-1; i++) {
                remain--;
                remain = max(remain, nums[i]);
                if (remain <= 0) return false;
            }
            return remain > 0;
        }
};
