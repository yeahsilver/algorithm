#include <iostream>

using namespace std;
 
#define MAX 51

int main(void) {
    int testCase;
    cin >> testCase;

    unsigned long long dp[MAX][MAX] = {};

    dp[1][0] = 1;

    for(int i = 1; i < MAX; i++) {
        dp[i][0] = 0;
        for(int j = 0; j < MAX; j++) {
            if(i == j || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    while(testCase--) {
        int N, M;
        cin >> N >> M;

        cout << dp[M][N] << '\n';
    }
}