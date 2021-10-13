#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int count = 0;
    int num = 665;

    while(1) {
        if(n == count) {
            cout << num << '\n';
            break;
        }

        num++;

        string s = to_string(num);

        if(s.find("666") != -1) {
            count++;
        }

       
    }
}