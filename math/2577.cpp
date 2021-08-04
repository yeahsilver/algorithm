#include <iostream>

using namespace std;

#define MAX 11

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    int value = A*B*C;

    int numbers[MAX] = {0, };

    while(value > 0) {
        numbers[value%10]++;
        value/=10;
    }

    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << '\n';
    }
    

    return 0;
}