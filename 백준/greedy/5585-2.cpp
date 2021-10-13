#include <iostream>

using namespace std;

int main(void) {
    int money;
    cin >> money;

    money = 1000-money;

    int coinTypes[6] = {500, 100, 50, 10, 5, 1};

    int cnt = 0;

    for(int i = 0; i < 6; i++) {
        cnt += money/coinTypes[i];
        money%=coinTypes[i];
    }

    cout << cnt << '\n';
}