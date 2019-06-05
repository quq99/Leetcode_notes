// BestTimeSellAndBuyStock.cpp

#include<vector>
using std::vector;
using std::max;

class BestTimeSellAndBuyStock {
    public:
        int maxProfit(vector<int>& prices) {
            const int len = prices.size();
            if (len < 2) {
                return 0;
            }
            int max_val = prices[0];
            int min_val = max_val;
            int res     = 0;
            for (int i = 1; i < len; ++i) {
                // if find new minimal value, reset min and max
                if (prices[i] < min_val) {
                    max_val = prices[i];
                    min_val = prices[i];
                }
                // if it is not minimal, and bigger than previous max, then update max
                else if (prices[i] > max_val) {
                    max_val = prices[i];
                    res = max(res, max_val - min_val);
                }
            }
            return res;
        }
};
