// MaxAreaOfIsland.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class MaxAreaOfIsland {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int max_val = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        int tmp = helper(grid, i, j, 0);
                        max_val = max(max_val, tmp);
                    }
                }
            }
            return max_val;
        }

        int helper(vector<vector<int>>& grid, int i, int j, int cur) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                cur++;
                if (i+1 < grid.size()) {
                    cur = helper(grid, i+1, j, cur);
                }
                if (i-1 >= 0) {
                    cur = helper(grid, i-1, j, cur);
                }
                if (j+1 < grid[0].size()) {
                    cur = helper(grid, i, j+1, cur);
                }
                if (j-1 >= 0) {
                    cur = helper(grid, i, j-1, cur);
                }
            }
            return cur;

        }
};
