#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reversePrint(string s) {
    if(!s.empty()) {
        reverse(s.begin(), s.end());
        cout << s;
    }
}
int main(void) {
    string str;
    getline(cin, str);

    string s = "";
    bool isReversed = true;

    for(int i = 0; i <= str.size(); i++) {
        char value = str[i];

        if(value == '<') {
            reversePrint(s);
            cout << value;
            isReversed = false;

            s = "";

        } else if(value == '>') {
            cout << value;
            isReversed = true;

        } else if(value == ' ') {
            
            reversePrint(s);
            s = "";
            
            cout << value;

        } else if(isReversed){
            s += value;

        } else {
            cout << value;
        }
    }

    reversePrint(s);
    cout << '\n';
}