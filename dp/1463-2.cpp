#include <iostream>

#define MAX 1000001

using namespace std;

int minimize(int a, int b) {
    return a > b ? b : a;
}

int main(void) {
    int n;
    cin >> n;

    int dp[MAX];

    dp[0] = dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;

        if(i % 3 == 0) {
            dp[i] = minimize(dp[i], dp[i/3]+1);
        } 
        
        if (i % 2 == 0) {
            dp[i] = minimize(dp[i], dp[i/2] + 1);
        }
    }

    cout << dp[n] << '\n';
}