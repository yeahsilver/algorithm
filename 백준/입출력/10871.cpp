#include <iostream>
using namespace std;

int main(void) {
    int N, num;
    cin >> N >> num;

    int* X = new int[N];

    for(int i = 0; i < N; i++) {
        cin >> X[i];
        if(X[i] < num) {
            cout << X[i] << ' ';
        }
    }
}