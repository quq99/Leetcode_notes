// MiniPathSum.cpp

#include<vector>
#include<algorithm>

using std::vector;
using std::min;

class MiniPathSum {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.size()==0 || grid[0].size()==0) return 0;
            int m = grid.size();
            int n = grid[0].size();
            // from right bottom to left top
            for (int i = m-1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) continue;
                    // last row, except last element
                    if (i == m - 1) {
                        grid[i][j] += grid[i][j+1];
                    }
                    // last column, except last element
                    else if (j == n - 1) {
                        grid[i][j] += grid[i+1][j];
                    }
                    // others
                    else {
                        grid[i][j] = min(grid[i][j]+grid[i+1][j], grid[i][j]+grid[i][j+1]);
                    }

                }
            }
            return grid[0][0];
        }
};
