// DegreeOfArray.cpp

#include<unordered_map>
#include<vector>
#include<algorithm>

using std::unordered_map;
using std::vector;
using std::max;
using std::min;

class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            unordered_map<int, int[3]> map;
            int degree = 1;
            for (int i = 0; i<nums.size(); i++) {
                if (map.find(nums[i]) == map.end()) {
                    map[nums[i]][0] = 1; // count
                    map[nums[i]][1] = i; // begin index
                    map[nums[i]][2] = i; // end index
                }
                else {
                    map[nums[i]][0] += 1;
                    map[nums[i]][2] = i;
                    degree = max(degree, map[nums[i]][0]);
                }
            }

            int res = INT_MAX;
            //cout << degree;
            for (int i = 0; i<nums.size(); ++i) {
                if (map[nums[i]][0] == degree) {
                    int len = map[nums[i]][2] - map[nums[i]][1] + 1;
                    res = min(res, len);
                }
            }
            return res;
        }
};
