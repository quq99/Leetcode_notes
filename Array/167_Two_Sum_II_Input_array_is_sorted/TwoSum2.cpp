// TwoSum2.cpp

#include<vector>
using std::vector;

class TwoSum2 {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> res = {0, 0};
            if (numbers.size() < 2) {
                return res;
            }
            int i = 0;
            int j = numbers.size()-1;
            while (i<j) {
                if (numbers[i]+numbers[j] < target) {
                    i++;
                }
                else if (numbers[i] + numbers[j] > target) {
                    j--;
                }
                else {
                    res = {i+1, j+1};
                    return res;
                }
            }
            return res;
        }
};
