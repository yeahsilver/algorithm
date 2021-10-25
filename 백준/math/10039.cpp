#include <iostream>

using namespace std;

int main(void) {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int value;
        cin >> value;

        if(value < 40) {
            value = 40;
        }

        sum += value;
    }

    cout << sum/5 << '\n';
}