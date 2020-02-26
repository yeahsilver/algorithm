#include <iostream>
using namespace std;
#define num 1000000000

int main(void){
    int N, total = 0;
    int dp[101][10]={};

    cin>>N;


    for(int i = 1; i<10; i++){
        dp[1][i] = 1;
    }

    for(int i = 2;i<=N;i++){
        for(int j = 0; j<10;j++){
            if(j == 0) dp[i][j] = dp[i-1][j+1];
            else if (j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][j-1]+ dp[i-1][j+1])%num;
        }
    }

    for(int i = 0; i<10; i++){
        total=(total+dp[N][i])%num;
    }

    cout<<total%num<<"\n";

}