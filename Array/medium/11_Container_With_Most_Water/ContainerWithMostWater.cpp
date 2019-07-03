// ContainerWithMostWater.cpp

#include<vector>
#include<algorithm>

using std::max;
using std::min;
using std::vector;

class ContainerWithMostWater {
    public:
        int maxArea(vector<int>& height) {
            int len = height.size();
            int left = 0;
            int right = len-1;
            int current = 0;
            int max_v = 0;
            while (left < right) {
                current = min(height[left], height[right]) * (right-left);
                max_v = max(max_v, current);
                if (height[left] < height[right]) {
                    left++;
                }
                else {
                    right--;
                }
            }
            return max_v;
        }
};
