#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        string s;
        cin >> s;

        stack<char> left;
        stack<char> right;

        for(auto& value: s){
            if(value == '>') {
                if(!right.empty()) {
                    char rightValue = right.top();
                    right.pop();
                    left.push(rightValue);
                }
            } else if(value == '<') {
                if(!left.empty()) {
                    char leftValue = left.top();
                    left.pop();
                    right.push(leftValue);
                }
            } else if (value == '-') {
                if(!left.empty()) {
                    left.pop();
                }
            } else {
                left.push(value);
            }
        }

        string answer = "";

        while(!left.empty()) {
            answer += left.top();
            left.pop();
        }

        reverse(answer.begin(), answer.end());

        while(!right.empty()) {
            answer += right.top();
            right.pop();
        }

        cout << answer << '\n';
    }    
}