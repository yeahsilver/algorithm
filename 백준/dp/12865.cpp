#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int weight[101], value[101] = {0,};
int dp[101][100001] = {0, };

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            dp[i][j] = dp[i-1][j];
            if(j - weight[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N][K] << '\n';
}