#pragma GCC optimize("O3","unroll-loops");

#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
