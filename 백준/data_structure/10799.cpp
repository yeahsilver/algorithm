#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    string str;
    getline(cin, str);

    int answer = 0;
    stack<char> s;

    char temp = ' ';
    for(int i = 0; i < str.size(); i++) {
        char value = str[i];

        if(value == '(') {
            s.push('(');

        } else if (value == ')') {
            if(temp == '('){
                s.pop();
                answer += s.size();

            } else if(temp == ')') {
                answer += 1;
                s.pop();
            }
        }
        temp = value;
    }

    cout << answer << '\n';
}