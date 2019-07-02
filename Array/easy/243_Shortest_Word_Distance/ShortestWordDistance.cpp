// ShortestWordDistance.cpp

#include<vector>
#include<algorithm>
#include<string>
using std::vector;
using std::min;
using std::string;

class ShortestWordDistance {
    public:
        int shortestDistance(vector<string>& words, string word1, string word2) {
            int index1 = -1;
            int index2 = -1;
            int res = INT_MAX;

            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    index1 = i;
                }
                if (words[i] == word2) {
                    index2 = i;
                }
                if (index1 != -1 && index2 != -1) {
                    res = min(res, abs(index2-index1));
                }
            }

            return res;
        }
};
