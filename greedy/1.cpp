#include <iostream>

using namespace std;

int main(void) {
    int money = 1260;
    int cnt = 0;

    int coinTypes[4] = {500, 100, 50, 10};

    for(int i = 0; i < 4; i++) {
        cnt+= money/coinTypes[i];
        money%=coinTypes[i];
    }

    cout << cnt << '\n';
}