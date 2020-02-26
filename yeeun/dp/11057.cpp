#include <iostream>
using namespace std;
#define num 10007

int main(void){
    int N, total = 0;
    int dp[1001][10]={};
    
    cin>>N;

    for(int i = 0; i < 10; i++){
        dp[1][i] = 1; 
    }

    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= num;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        total = (total + dp[N][i]) % num;
    }
    cout<< total % num;
}