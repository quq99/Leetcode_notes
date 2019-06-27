// ValidMountainArray.cpp

#include<vector>
using std::vector;

class ValidMountainArray {
    public:
        bool validMountainArray(vector<int>& A) {
            if (A.size() < 3) {
                return false;
            }
            // find first decrease number
            int i = 1;
            for (; i < A.size(); i++) {
                if (A[i] <= A[i-1]) break;
            }
            // first element is bigger than second
            // all of the array is ascend
            if (i == 1 || i == A.size()) {
                return false;
            }
            // check the right part
            for (int j = i; j < A.size(); j++) {
                if (A[j] >= A[j-1]) return false;
            }
            return true;
        }
};
