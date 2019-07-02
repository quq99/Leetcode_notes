// FindCommonChar.cpp

#include<vector>
#include<string>
#include<algorithm>

using std::vector;
using std::string;
using std::min;

class FindCommonChar {
    public:
        vector<string> commonChars(vector<string>& A) {
            vector<int> arr(26, INT_MAX); // arr stores the common characters
            vector<string> res;
            for (auto s : A) {
                vector<int> arr2(26, 0);
                for (auto ch : s) {
                    arr2[ch - 'a']++;
                }
                // update arr, use min to get intersection set
                for (int i = 0; i < 26; i++) {
                    arr[i] = min(arr[i], arr2[i]);
                }
            }

            for (int i = 0; i < 26; i++) {
                while (arr[i]) {
                    res.push_back(string(1, i+'a'));
                    arr[i]--;
                }
            }
            return res;
        }
};
