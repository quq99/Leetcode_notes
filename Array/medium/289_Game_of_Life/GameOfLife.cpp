// GameOfLife.cpp

#include<vector>
#include<algorithm>
using std::max;
using std::min;
using std::vector;

class GameOfLife {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size();
            if (m==0) return;
            int n = board[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int count = 0;
                    for (int I = max(0,i-1); I < min(m,i+2); I++) {
                        for (int J = max(0, j-1); J < min(n, j+2); J++) {
                            if (i == I && j == J) continue;
                            count += board[I][J] & 1;
                        }
                    }
                    if (count == 3 || (board[i][j]==1 && count==2))
                        board[i][j] |= 2; // | to 10b, set the second bit to be 1.
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    board[i][j] >>= 1;
                }
            }

        }
};
