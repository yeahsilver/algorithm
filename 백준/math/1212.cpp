#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    

    for(int i = 0; i < str.size(); i++) {
        char value = str[i];

        switch(value) {
            case '0': 
                if(!i) {
                    cout << "0";
                } else {
                    cout << "000";
                }

                break;

            case '1': 
                if(!i) {
                    cout << "1";
                } else {
                    cout << "001";
                }

                break;

            case '2':
                if(!i) {
                    cout << "10";
                } else {
                    cout << "010";
                }

                break;

            case '3':
                if(!i) {
                    cout << "11";
                } else {
                    cout << "011";
                }
                break;
            
            case '4': 
                cout << "100";
                break;
            
            case '5':
                cout << "101";
                break;

            case '6': 
                cout << "110";
                break;

            case '7':
                cout << "111";
                break;
        }
    }
}