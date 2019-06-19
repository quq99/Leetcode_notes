// CanPlaceFlowers.cpp

#include<vector>
using std::vector;

class CanPlaceFlowers {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            if (!n) {
                return true;
            }

            int count = 0;
            int tmp_count = 1;
            for (int i = 0; i < flowerbed.size(); i++) {
                if (flowerbed[i] == 0) {
                    tmp_count++;
                    // have 3 continues 0s, reset tmp_count to 1
                    if (tmp_count == 3) {
                        count++;
                        tmp_count = 1;
                    }
                }
                // when meet with 1, reset tmp_count to 0
                else {
                    tmp_count = 0;
                }
            }
            // if end with two continues 0s,
            // can place the flower at the last position
            if (tmp_count == 2) count++;

            return count >= n;
        }
};
