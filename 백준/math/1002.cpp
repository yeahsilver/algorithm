#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt(pow(x2-x1,2) + pow(y2-y1, 2));
        double sub = r1 > r2 ? r1 - r2 : r2 - r1;

        if(d == 0 && r1 == r2) {
            cout << -1 << '\n';

        } else if (r1+r2 == d || sub == d) {
            cout << 1 << '\n';

        } else if (sub < d && r1+r2 > d) {
            cout << 2 << '\n';

        } else {
            cout << 0 << '\n';
        }
    }
}