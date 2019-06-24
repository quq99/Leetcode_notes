// MaxDistance.cpp

#include<algorithm>
#include<vector>

using std::max;
using std::vector;

class MaxDistance {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int len = seats.size();
            if (len==1) return 1;
            // init first possible position and length
            int pos1 = 0; // position of 1

            for (int i = 0; i < len; i++, pos1++) {
                if (seats[i]==1) break;
            }
            int max_len = pos1;

            // traverse array
            for (int i = pos1+1; i < len; ++i) {
                if (seats[i]==1) {
                    max_len = max(max_len, (i - pos1)/2);
                    pos1 = i;
                }
            }
            // if end with 0
            if (seats[len-1] == 0) {
                max_len = max(max_len, len - 1 - pos1);
            }

            return max_len;
        }
};
