#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n, greater<int>());

    int total = 0;

    for(int i = 0; i < n; i++) {
        total += (A[i]*B[i]);
    }

    cout << total << '\n';
}