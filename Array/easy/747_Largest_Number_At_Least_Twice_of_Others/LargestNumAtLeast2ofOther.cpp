// LargestNumAtLeast2ofOther.cpp

#include<vector>
#include<algorithm>

using namespace std;

class LargestNumAtLeast2ofOther {
    public:
        int dominantIndex(vector<int>& nums) {
            if (nums.size()==1) return 0;
            int first = nums[0];
            int second = INT_MIN;
            int index = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > first) {
                    second = first;
                    first = nums[i];
                    index = i;
                }
                else if (nums[i] < first && nums[i] > second) {
                    second = nums[i];
                }
            }
            if (first >= second*2) {
                return index;
            }
            else {
                return -1;
            }
        }
};
