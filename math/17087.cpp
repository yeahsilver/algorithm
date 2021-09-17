#include <iostream>

using namespace std;

int gcd(long long a, long long b) {

    long long c;

    while(b!= 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int main(void) {
    int N;
    long long S;
    cin >> N >> S;
    
    long long* numbers = new long long[N+1];

    for(int i = 0; i < N; i++) {
        long long value;
        cin >> value;

        numbers[i] = abs(S-value);
    }

    long long value = numbers[0];

    for(int i = 1; i < N; i++) {
        value = gcd(value, numbers[i]);
    }

    cout << value << '\n';
}