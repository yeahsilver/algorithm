#include <iostream>

using namespace std;

int main(void) {
    int count = 1;
    while(1) {
        int L, P, V;
        cin >> L >> P >> V;

        if(L == 0 && P == 0 && V == 0) {
            break;
        }

        int quotient = V/P;
        int remainder = V%P;

        if(remainder > L) {
            remainder = L;
        }

        cout << "Case " << count << ": " <<  L * quotient + remainder << '\n';
        count++;
    }
}