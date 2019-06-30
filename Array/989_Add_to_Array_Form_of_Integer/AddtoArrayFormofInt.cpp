// AddtoArrayFormofInt.cpp

#include<vector>
using std::vector;

class AddtoArrayFormofInt {
    public:
        vector<int> addToArrayForm(vector<int>& A, int K) {
            if (K==0) return A;

            int flag = 0;
            int i = A.size()-1;
            while((flag || K ) && i>=0) {
                int remain = K % 10;
                if (A[i]+remain+flag > 9) {
                    A[i] = (A[i] + remain + flag) % 10;
                    // first time flag is 0
                    if (flag == 0) {
                        flag = 1;
                    }
                }
                else {
                    A[i] += remain + flag;
                    flag = 0;
                }
                // update to next element
                K /= 10;
                i--;
            }
            // deal with the rest element of K
            while (flag || K) {
                int remain = K % 10;
                A.insert(A.begin(), (flag+remain)%10);
                flag = (flag+remain) / 10;
                K /= 10;
            }
            return A;
        }
};
