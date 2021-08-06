#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int main(void) {
    int N, K;
    cin >> N >> K;

    int* coins = new int[N+1];

    for(int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    unsigned long dp[MAX] = {0,};
    dp[0] = 0; 

    for(int i = 1; i <= K; i++) {
        dp[i] = __INT_MAX__;
    }

    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }

    if(dp[K] == __INT_MAX__) {
        cout << -1 << '\n';
    } else {
        cout << dp[K] << '\n';
    }
}