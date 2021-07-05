#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;

    int answer = 0;

    (s[0] == 'c') ? answer += 26 : answer += 10;

    for(int i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) {
            if(s[i] == 'c') {
                answer *= 25;
            } else {
                answer *= 9;
            }
        } else {
            if(s[i] == 'c') {
                answer *= 26;
            } else {
                answer *= 10;
            }
        }
    }

    cout << answer << '\n';
}