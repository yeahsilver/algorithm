#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int c;

    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        int* numbers = new int[num+1];

        for(int i = 0; i < num; i++) {
            cin >> numbers[i];
        }

        long long answer = 0;

        for(int i = 0; i < num; i++) {
            for(int j = i+1; j < num; j++) {
                answer += GCD(numbers[i], numbers[j]);
            }
        }

        cout << answer << '\n';
    }
}