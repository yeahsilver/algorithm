#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int cnt = 0;

    for(int i = 0; i <s.size(); i++) {
        if(i != s.size()) {
            if(s[i] == 'c') {
                if(s[i+1] == '=' || s[i+1] == '-') {
                    cnt++;
                    i++;
                }  else {
                    cnt++;
                }
            } else if (s[i] == 'd') {
                if(s[i+2] != s.size()-2 && s[i+1] == 'z' && s[i+2] == '=') {
                    cnt++;
                    i+=2;
                } else if (s[i+1] == '-') {
                    cnt++;
                    i++;
                } else {
                    cnt++;
                }
            } else if (s[i] == 'l') {
                if(s[i+1] == 'j') {
                    cnt++;
                    i++;
                }
                else {
                    cnt++;
                }
            } else if (s[i] == 'n') {
                if(s[i+1] == 'j') {
                    cnt++;
                    i++;
                } else {
                    cnt++;
                }
                
            } else if (s[i] == 's') {
                if(s[i+1] == '=') {
                    cnt++;
                    i++;
                } else {
                    cnt++;
                }
            } else if(s[i] == 'z') {
                if(s[i+1] == '=') {
                    cnt++;
                    i++;
                } else {
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}