// XofaKindInCards.cpp

#include<vector>
#include<unordered_map>
#include<numeric>
using std::vector;
using std::unordered_map;

class XofaKindInCards {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            unordered_map<int, int> map;
            for (int d: deck) {
                map[d]++;
            }
            int res = 0;
            for (auto m : map) {
                res = std::gcd(m.second, res);
            }
            return res > 1;
        }
};
