#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int n;
    string str;
    stack<char> s;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        getline(cin, str);
        str+= " ";
        string answer;

        for(int i = 0; i < str.size(); i++) {
        
            if(str[i] != ' ') {
                s.push(str[i]);
                
            } else {
                while(!s.empty()) {
                    answer+=s.top();
                    s.pop();
                }
                answer+=" ";
            }
        }

        cout << answer << '\n';
    }

    return 0;
}