// MiniSizeSubarraySum.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::min;

class MiniSizeSubarraySum {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int len = nums.size();
            if (len == 0) return 0;
            if (len == 1) return nums[0]>=s ? 1 : 0;
            vector<int> sums;
            int sum = 0;
            for (auto n : nums) {
                sum += n;
                sums.push_back(sum);
            }
            int res = INT_MAX;
            for (int i = 0; i < len; i++) {
                int end = findIndex(sums, sums[i]-nums[i]+s);
                if (end == len) break;
                else {
                    res = min(res, end - i + 1);
                }
            }
            return res==INT_MAX ? 0 : res;
        }

        int findIndex(vector<int>& sums, int target) {
            int l = 0;
            int r = sums.size() - 1;
            if (target > sums[r]) return r+1; // can not find return len of sums.
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (sums[mid] < target) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            return l;
        }
};


class MiniSizeSubarraySum2 {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            if (nums.size()==0) return 0;
            if (nums.size()==1) return nums[0]>=s ? 1 : 0;

            int res = INT_MAX;
            int sum = 0;
            // window. left point and i for right point
            int left = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                while (left <= i && sum >= s) {
                    res = min(res, i-left+1);
                    sum -= nums[left];
                    left++;
                }
            }
            return res==INT_MAX ? 0 : res;
        }
};
