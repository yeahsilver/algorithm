#include <iostream>
using namespace std;

int Min (int a,int b){
    return a > b ? b : a;
}

int main(void){
    int N;
    int dp[1000001] = {};
    cin>>N;

    dp[0] = dp[1] = 0;

    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = Min(dp[i],dp[i/2] + 1);
        if(i%3 == 0)dp[i] =  Min(dp[i], dp[i/3] + 1);
    }

    cout<<dp[N];
}   