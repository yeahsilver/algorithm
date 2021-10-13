#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    long long answer = 0LL;
    
    for(int i = 1; i <= n; i++) {
        answer += i * (n/i);
    }

    cout << answer;
}