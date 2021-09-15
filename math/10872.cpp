#include <iostream>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    long long answer = 1;

    for(int i = 1; i <= num; i++) {
        answer*=i;
    }

    cout << answer << '\n';
}