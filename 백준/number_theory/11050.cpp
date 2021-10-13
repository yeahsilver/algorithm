#include <iostream>

using namespace std;

int factorial(int x) {
    int result = 1;

    for(int i = x; i > 0; i--) {
        result *= i;
    }

    return result;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    int binominalCoefficient = factorial(N) / (factorial(K) * factorial(N-K));
    cout << binominalCoefficient << '\n';

    return 0;
}