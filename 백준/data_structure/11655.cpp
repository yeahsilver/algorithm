#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    getline(cin, str);

    for(int i = 0; i < str.size(); i++) {
        char value = str[i];

        if(value >= 'A' && value <= 'Z') {
            char changedValue = value + 13;
            
            if(changedValue > 'Z') {
                cout << char((changedValue-'Z')+'A'-1);

            } else {
                cout << changedValue;

            }

        } else if(value >= 'a' && value <= 'z') {
            int changedValue = value + 13;

            if(changedValue > 122) {
                cout << char((changedValue-'z')+'a'-1);

            } else {
                cout << char(changedValue);

            }

        } else {
            cout << value;

        }
    }
}