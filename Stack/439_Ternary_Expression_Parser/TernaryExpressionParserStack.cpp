// TernaryExpressionParserStack.cpp

#include<stack>
#include<vector>
#include<string>

using std::vector;
using std::stack;
using std::string;

class TernaryExpressionParserStack {
    public:
        string parseTernary(string expression) {
            if (expression.size() <= 1) {
                return expression;
            }
            stack<char> st;
            for (int i = expression.size()-1; i >= 0; i--) {
                char ch = expression[i];
                if (!st.empty() && st.top() == '?') {
                    st.pop(); // ?
                    char first = st.top();
                    st.pop(); // exp1
                    st.pop(); // :
                    char second = st.top();
                    st.pop(); // exp2
                    if (ch == 'T') st.push(first);
                    else st.push(second);
                }
                else {
                    st.push(ch);
                }
            }
            return string(1, st.top());
        }
};

