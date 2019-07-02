// KDiffPairs.cpp

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class KDiffPairs {
    public:
        int findPairs(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            for (int n : nums) {
                map[n] += 1;
            }
            int count = 0;
            for (auto m : map) {
                if ( (k==0 && m.second > 1) ||
                     (k>0 && map.find(m.first+k) != map.end())) {
                    count++;
                }
            }

            return count;

        }
};
