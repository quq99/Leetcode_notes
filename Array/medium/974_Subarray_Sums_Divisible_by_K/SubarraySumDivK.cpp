// SubarraySumDivK.cpp

#include<vector>

using std::vector;

class SubarraySumDivK {
    public:
        int subarraysDivByK(vector<int>& A, int K) {
            vector<int> map(K, 0);
            int count = 0;
            int sum = 0;
            int mod = 0;
            for (auto num : A) {
                sum += num;
                if (sum % K == 0) count++;
                // if sum % K is negative, convert it to positive
                mod = sum % K >= 0 ? sum % K : K + sum % K;
                count += map[mod];
                map[mod]++;
            }

            return count;
        }
};
