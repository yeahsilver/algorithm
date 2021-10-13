#include <iostream>

using namespace std;

#define MAX 1001

int N, K;
int dp[MAX][MAX] = {0,};

int main(void) {
    cin >> N >> K;

    for(int i = 1; i < N + 1; i++) {
        for(int j = 0; j < K+1; j++) {
            if(i == j || j == 0) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K];    
}