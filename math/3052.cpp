#include <iostream>

using namespace std;

int main(void) {
    int numbers[43] = {0, };

    for(int i = 0; i < 10; i++) {
        int value;
        cin >> value;

        numbers[value%42]++;
    }

    int count = 0;

    for(int i = 0; i < 43; i++) {
        if(numbers[i] > 0) {
            count++;
        }
    }

    cout << count << '\n';
}