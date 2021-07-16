#include <iostream>

using namespace std;

int main(void) {
    int A = 300, B = 60, C = 10;

    int countA = 0, countB = 0, countC = 0;

    int time;
    cin >> time;

    countA = time/A;
    time -= countA * A;

    countB = time/B;
    time -= countB * B;

    countC = time/C;
    time -= countC * C;

    if(time != 0) { cout << -1 << '\n'; return 0; }

    cout << countA << ' ' << countB << ' ' << countC << '\n';
}