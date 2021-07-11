#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define MAX 10001

int main(void) {
    int n;
    cin >> n;


    stack<int> s;

    for(int i = 0; i < n; i++) {
        int value;
        string str;

        cin >> str;

        if(str == "push"){
            cin >> value;
            s.push(value);

        } else if(str == "top") {
            if(!s.empty()) {
                cout << s.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
            
        } else if(str == "size") {
            cout << s.size() << '\n';

        } else if (str == "empty") {
            if(!s.empty()) {
                cout << 0 << '\n';

            } else {
                cout << 1 << '\n';
            }
        } else if(str == "pop") {
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}