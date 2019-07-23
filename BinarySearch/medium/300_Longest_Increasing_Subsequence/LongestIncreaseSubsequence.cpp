// LongestIncreaseSubsequence.cpp

#include<vector>

using std::vector;

class LongestIncreaseSubsequence {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();
            if (nums.size() < 2) return len;
            vector<int> tails(len, 0);
            int size = 0;
            for (auto n : nums) {
                int l = 0;
                int r = size;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (n <= tails[mid]) {
                        r = mid;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                if (r == size) tails[size++] = n;
                else tails[l] = n;
            }
            return size;
        }
};
