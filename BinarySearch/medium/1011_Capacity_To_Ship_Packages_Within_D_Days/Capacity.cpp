// Capacity.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class Capacity {
    public:
        int shipWithinDays(vector<int>& weights, int D) {
            int l = 0;
            int r = 0;
            for (auto n : weights) {
                r += n;
                l = max(l, n);
            }
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (valid(weights, mid, D)) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            return l;
        }

        bool valid(vector<int>& nums, int mid, int bound) {
            int count = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > mid) {
                    count++;
                    sum = nums[i];
                }
                else if (sum + nums[i] == mid) {
                    count++;
                    sum = 0;
                }
                else {
                    sum += nums[i];
                }
                if (count > bound) return false;
            }
            if (sum > 0) count++;
            return count <= bound;
        }
};
