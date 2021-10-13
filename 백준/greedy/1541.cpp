#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    bool isMinus = false;
    
    int answer = 0;
    string value = "";

    for(int i = 0; i <= s.size(); i++) {
        
        if(s[i] == '+' || s[i] == '-' || s[i] == '\0') {

            if(isMinus) {
                answer -= stoi(value);

            } else {
                answer += stoi(value);
            }


            if(s[i] == '-') {
                isMinus = true;
            }

            value = "";

        } else {
            value += s[i];
        }
    }

    cout << answer << '\n';
}