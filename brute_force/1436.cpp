#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    int count = 0;
    int expiredNum = 665;
    string s;

    while(1) {
        s = to_string(expiredNum);

        if(s.find("666") != -1) {
            count++;
        }

        if(count == num) {
            cout << expiredNum << '\n';
            break;
        }

        expiredNum++;
    }
}