#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void print(vector<char> answer) {
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    cout << '\n';
}

int main(void) {
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    stack<char> s;

    int start = 0;
    int end = str.size()-1;

    vector<char> answer(str.size());

    for(int i = 0; i < str.size(); i++) {
        int value = str[i];

        if(s.empty()) {
            s.push(value);

        } else {
            int top = s.top();

            if(value == top) {
                s.pop();

                answer[start++] = top;
                answer[end--] = value;

            } else {
                s.push(str[i]);
            }
        }
    }
    
    if(s.empty()) {
        print(answer);
    } else {
        if(s.size() == 1) {
            answer[start] = s.top();
            s.pop();
            print(answer);
        } else {
            cout << "I'm Sorry Hansoo\n";
        }
    }
}