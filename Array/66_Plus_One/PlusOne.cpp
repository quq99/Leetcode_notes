// PlusOne.cpp

#include<vector>

using std::vector;

class PlusOne {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int len = digits.size();

            for (int i = len-1; i>= 0; i--) {
                // when this position is 9, set to 0,
                // and consider the previous position.
                if (digits[i] == 9) {
                    digits[i] = 0;
                }
                // when this position is not 9, add 1
                // and end the loop.
                else {
                    digits[i] += 1;
                    break;
                }
            }
            // if all numbers are 9, when loop done
            // the first number would be 0, so add
            // 1 to the beginning.
            if (digits[0] == 0) {
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
};
