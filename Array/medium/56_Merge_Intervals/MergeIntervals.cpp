// MergeIntervals.cpp

#include<vector>
#include<algorithm>
using std::max;
using std::vector;

class MergeIntervals {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.size() < 2) {
                return intervals;
            }
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
                    return a[0] < b[0];
                    });
            vector<vector<int>> res;
            int left = intervals[0][0];
            int right = intervals[0][1];
            for (int i = 1; i < intervals.size(); i++) {
                // combine
                if (right >= intervals[i][0]) {
                    right = max(intervals[i][1], right);
                    //left = min(intervals[i][0], left);
                }
                // push last result and update 'left' 'right'
                else {
                    res.push_back({left, right});
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
            }
            res.push_back({left, right});
            return res;
        }
};
