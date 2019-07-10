// TernaryExpressionParser.cpp

#include<stack>
#include<vector>
#include<string>

using std::vector;
using std::stack;
using std::string;

class TernaryExpressionParser {
    public:
        string parseTernary(string expression) {
            stack<char> st;
            return helper(expression, st);
        }

        string helper(string str, stack<char>& st) {
            if (str.size()==1) return str;

            if (str[1] == '?') {
                st.push(str[0]);
                return helper(str.substr(2), st);
            }

            else {
                char tf = st.top();
                st.pop();
                if (tf == 'T') {
                    // get left result of ':'
                    string firstStr(1, str[0]);
                    // omit right result of this sub expression
                    // and get the rest string
                    if (str.substr(2).find(":") != string::npos) {
                        string subStr = str.substr(2);
                        int countComma = 1;
                        int pos = 0;
                        for (pos = 0; pos < subStr.size(); pos++) {
                            if (subStr[pos]=='?') countComma++;
                            else if (subStr[pos]==':') countComma--;
                            if (!countComma) break;
                        }
                        firstStr += subStr.substr(pos);
                    }

                    return helper(firstStr, st);
                }
                else {
                    return helper(str.substr(2), st);
                }
            }
        }
};

