// KSmallestInSortArray2D.cpp

#include<vector>

using std::vector;

class KSmallestInSortArray2D {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int m = matrix.size();
            int n = matrix[0].size();
            int l = matrix[0][0];
            int r = matrix[m-1][n-1]+1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                // count the number of element that is smaller or equal than mid
                int count = 0;
                int j = n-1;
                for (int i = 0; i < m; i++) {
                    while (j>=0 && matrix[i][j]>mid) j--;
                    count += j+1;
                }
                if (count < k) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            return l;
        }
};
