// ThirdMaxNumber.cpp

#include<vector>
using std::vector;

class ThirdMaxNumber {
    public:
        int thirdMax(vector<int>& nums) {
            int first = INT_MIN;
            int second = first;
            int third = second;
            int count = 0;
            bool once = true;
            for (int i = 0; i < nums.size(); ++i) {
                // [1, 2, INT_MIN, INT_MIN]
                if (nums[i] == INT_MIN && once) {
                    count++;
                    once = false;
                }

                if (nums[i]==first || nums[i]==second) continue;

                if (nums[i] > first) {
                    third = second;
                    second = first;
                    first = nums[i];
                    count++;
                }
                else if (nums[i] > second) {
                    third = second;
                    second = nums[i];
                    count++;
                }
                else if (nums[i] > third) {
                    third = nums[i];
                    count++;
                }
            }
            if (count < 3) return first;
            else return third;
        }
};
