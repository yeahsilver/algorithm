#include <iostream>
using namespace std;
#define num 1000000000;

int main(void){
    int N,k;
    long dp[201][201] = {};
    
    cin>>N>>k;

    for(int i = 0; i <= N; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= k; i++){
        for(int j = 0; j <= N; j++){
            for(int l = 0; l <= j; l++)
            dp[i][j] += dp[i-1][l];
            dp[i][j]%=num;
        }
    }
    cout<<dp[k][N];

}