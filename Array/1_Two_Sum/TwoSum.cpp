#include<bits/stdc++.h>

class TwoSum {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int len = nums.size();
            vector<int> res;
            // edge case, if len of vector nums smaller than 2
            // return a null vector.
            if (len < 2) {
                return res;
            }

            // the format of hash map is <value_of_current_number, index>
            unordered_map<int, int> map;
            for (int i=0; i<len; i++) {
                int remain = target - nums[i];
                // if we find remain in hash map, push back to map
                if (map.find(remain) != map.end()) {
                    res.push_back(map[remain]);
                    res.push_back(i);
                    return res;
                }
                // if can not find, push this value and index to hash map.
                else {
                    map[nums[i]] = i;
                }
            }
            return res;
        }
};
