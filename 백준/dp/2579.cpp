#include <iostream>
using namespace std;

int max(int a, int b){ return a>b ? a : b; }

int main(void){
    int a[10001] = {0,};
    int dp[10001] = {0,};
    int N;

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>a[i];
    }

    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = max(a[1] + a[3], a[2] + a[3]);

    for(int i=4;i<=N;i++){
        dp[i] = max(dp[i-3]+a[i]+a[i-1],dp[i-2]+a[i]);
        
    }

    cout<<dp[N];

}