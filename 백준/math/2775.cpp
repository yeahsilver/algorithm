#include <iostream>

using namespace std;

#define MAX 15

int main(void) {
    int testCase;
    cin >> testCase;
    
    int dp[MAX][MAX] = {0, };

    for(int i = 1; i < MAX; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {
            for(int k = 1; k <= j; k++) {
                dp[i][j] += dp[i-1][k];
            }
         }
    }

    while(testCase--) {
        int K, N;
        cin >> K >> N;

        cout << dp[K][N] << '\n';
    }

    return 0;
}