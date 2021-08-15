#include <iostream>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;

    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int M, N;
    cin >> M >> N;

    int sum = 0;

    bool isFirst = true;
    int first = 0;
    for(int i = M; i <= N; i++) {
        if(isPrime(i)) {
            if(isFirst) {
                first = i;
                isFirst = false;
            }

            sum+=i;
        }
    }
    
    if(isFirst) {
        cout << -1 << '\n';
    } else {
        cout << sum << '\n' << first << '\n';
    }
}
    