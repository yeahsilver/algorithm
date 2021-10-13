#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    bool isPossible = true;
    stack<char> stack;

    int temp = 1;
    long long total = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            temp*=2;
            stack.push(s[i]);
            
        } else if (s[i] == '[') {
            temp*=3;
            stack.push(s[i]);

        } else if(s[i] == ')') {
            if(stack.empty()) {
                isPossible = false;
                break;
            }

            if(stack.top() == '(') {
                if(s[i-1] == '(') {
                    total+=temp;
                }
                temp/=2;
                stack.pop();

            } else {
                isPossible = false;
                break;
            }
        } else if(s[i] == ']') {
            if(stack.empty()) {
                isPossible = false;
                break;
            }
            if(stack.top() == '[') {
                if(s[i-1] == '[') {
                    total += temp;
                }
                temp/=3;
                stack.pop();
            } else {
                isPossible = false;
                break;
            }
        }
    }
    (!isPossible || !stack.empty()) ? cout << 0 << '\n' : cout << total << '\n';
}