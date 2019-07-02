// MoveZeros.cpp

#include<vector>
using std::vector;

class MoveZeros {
    public:
        void moveZeroes(vector<int>& nums) {
            // count indicate the non zero element position
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != 0) {
                    swap(nums[count] , nums[i]);
                    count++;
                }
            }
        }
        void swap(int& a, int& b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
};
