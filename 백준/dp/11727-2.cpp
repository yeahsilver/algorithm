#include <iostream>

using namespace std;

#define MAX 1000

int main(void) {
    int num;
    cin >> num;

    int dp[MAX];

    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= num; i++) {
        dp[i] = ((dp[i-2]*2) + dp[i-1])%10007;
    }

    cout << dp[num] << '\n';
}