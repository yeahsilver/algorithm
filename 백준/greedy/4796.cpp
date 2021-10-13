#include <iostream>

using namespace std;

int main(void) {
    int test_case = 1;

    while(1) {
        int L, P, V;
        cin >> L >> P >> V;

        if(P == 0 && V == 0 && L == 0) break;

        int quotient = V/P;

        int remainder = V%P;

        if(remainder > L) {
            remainder = L;
        }

        cout << "Case " << test_case << ": " << quotient*L + remainder << '\n';
        test_case++;
    }
}