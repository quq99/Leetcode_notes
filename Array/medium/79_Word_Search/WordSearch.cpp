// WordSearch.cpp

#include<vector>
#include<string>
using std::string;
using std::vector;

class WordSearch {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            if (m==0) return false;
            int n = board[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0]) {
                        bool bo = helper(board, word, 0, i, j);
                        if (bo) return true;
                    }
                }
            }
            return false;
        }

        bool helper(vector<vector<char>>& board, string& word, int index, int i, int j) {
            if (index == word.size()) return true;
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
            if (board[i][j] != word[index]) return false;
            char cur = board[i][j];
            board[i][j] = '0'; // already check this position
            bool res = helper(board, word, index+1, i-1, j) ||
                helper(board, word, index+1, i+1, j) ||
                helper(board, word, index+1, i, j-1) ||
                helper(board, word, index+1, i, j+1);
            board[i][j] = cur; // put back
            return res;
        }
};
