// SplitArrayLargestSum.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class SplitArrayLargestSum {
    public:
        int splitArray(vector<int>& nums, int m) {
            // get max element in the array
            // get sum of array
            // this are two boundary
            int max_v = 0;
            long sum = 0;
            for (auto n : nums) {
                sum += n;
                max_v = max(max_v, n);
            }
            if (m == 1) return int (sum);
            // binary search
            long l = max_v;
            long r = sum;
            while (l < r) {
                long mid = l + (r - l) / 2;
                if (valid(mid, m, nums)) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            return int (l);
        }

        // check that given a sum_bound, if we can split the array in less than m chunks
        bool valid(long sum_bound, int m, vector<int>& nums) {
            int count = 1;
            long sum = 0;
            for (auto n : nums) {
                sum += n;
                // if sum greater than bound, we need one more split
                // so count++
                if (sum > sum_bound) {
                    sum = n;
                    count++;
                    if (count > m) return false;
                }
            }
            return true;
        }
};
