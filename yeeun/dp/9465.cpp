#include <iostream>
using namespace std;

int max(int a, int b){
    return a>b ? a : b; 
}

int main(void){
    int dp[2][100001] = {};
    int a[2][100001] = {};
    int T;

    cin>>T;

    while(T--){
        int N;
        cin>>N;

        for(int i = 0; i<=1; i++){
            for(int j = 1; j<=N; j++){
                cin>>a[i][j];
            }
        }

        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = a[0][1];
        dp[1][1] = a[1][1];

        for(int i = 2; i <= N; i++){
            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + a[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + a[1][i];
        }

        cout<<max(dp[0][N],dp[1][N])<<"\n";
    }
}