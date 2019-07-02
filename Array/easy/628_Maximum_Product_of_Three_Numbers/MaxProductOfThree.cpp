// MaxProductOfThree

#include<vector>
#include<algorithm>
using std::max;
using std::vector;

class MaxProductOfThree {
    public:
        int maximumProduct(vector<int>& nums) {
            int max1 = INT_MIN; // biggest
            int max2 = INT_MIN; // second biggest
            int max3 = INT_MIN; // third biggest
            int min1 = INT_MAX; // smallest
            int min2 = INT_MAX; // second smallest

            for (int num : nums) {
                if (num > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = num;
                }
                else if (num > max2) {
                    max3 = max2;
                    max2 = num;
                }
                else if (num > max3) {
                    max3 = num;
                }

                if (num < min1) {
                    min2 = min1;
                    min1 = num;
                }
                else if (num < min2) {
                    min2 = num;
                }
            }

            return max(max1*max2*max3, min1*min2*max1);
        }
};
