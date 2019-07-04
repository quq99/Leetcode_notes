// SubarraySumIsK.cpp

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class SubarraySumIsK {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            int count = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (map.find(sum-k) != map.end()) {
                    count += map[sum-k]; // subarray end in current position
                }
                if (sum == k) count++; // subarray start 0 and end in current position
                map[sum] += 1; // put new sum into hash map
            }
            return count;
        }
};
