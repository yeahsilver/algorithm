#include <iostream>

using namespace std;

int main(void) {
    int quarter = 25, dime = 10, nickel = 5, penny = 1;

    int test_case;
    cin >> test_case;

    while(test_case--) {
        int count[4] = {0, };

        int money;
        cin >> money;

        count[0] = money/quarter;
        money -= count[0] * quarter;

        count[1] = money/dime;
        money -= count[1] * dime;

        count[2] = money/nickel;
        money -= count[2] * nickel;

        count[3] = money/penny;
        money -= count[3] * penny;

        for(int i = 0; i < 4; i++) {
            cout << count[i] << ' ';
        }

        cout << '\n';
    } 
}