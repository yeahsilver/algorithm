#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1) {
        string s;
        getline(cin, s);

        if(s == ".") {
            break;
        }

        stack<char> st;
        bool flag = true;

        for(int i = 0; i < s.size(); i++) {
            char value = s[i];

            if(value == '(' || value == '[') {
                st.push(value);

            } else if(value == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }

            } else if (value == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if(st.empty() && flag) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}