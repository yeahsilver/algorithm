#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void print(stack<char> left, stack<char> right) {
    vector<char> v;

    while(!left.empty()) {
        v.push_back(left.top());
        left.pop();
    }

    for(int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }
}

int main(void) {
    stack<char> left;
    stack<char> right;

    string s;
    int n;
    cin >> s >> n;

    for(int i = 0; i < s.size(); i++) {
        left.push(s[i]);
    }

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if(c == 'L') {
            if(!left.empty()){
                char top = left.top();
                left.pop();
                right.push(top);
            }

        } else if (c == 'D') {
            if(!right.empty()) {
                char top = right.top();
                right.pop();
                left.push(top);
            }

        } else if(c == 'B') {
            if(!left.empty()) {
                left.pop();
            }
    
        } else if(c == 'P') {
            char value;
            cin >> value;
            left.push(value);
        }
    }
    
    print(left, right);
}