// FindDup2.cpp

#include<vector>

using std::vector;

class FindDup2 {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size()-1;
            int low = 1;
            int high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                int count = 0;
                for (auto n : nums) {
                    if (n <= mid)  count++;
                }
                if (count > mid) high = mid;
                else low = mid+1;
            }
            return low;
        }
};
