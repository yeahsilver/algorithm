#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    if(n < 10) {
        cout << n << '\n';
        return 0;
    }

    long long result = 0;

    int digits = 1;

    for(int i = 9; i <= n; i*=10) {
        n-=i;
        result += digits*i;
        digits++;
    }
    
    result += (digits*n);

    cout << result << '\n';

    return 0;
}