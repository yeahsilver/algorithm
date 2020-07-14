#include <iostream>
using namespace std;

int Max(int a, int b){ return a > b ? a : b; }
int main(void){
    int N, max = 0;
    int a[10001] = {};
    int dp[10001] = {};
    
    cin>>N;

    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = Max(dp[i], dp[i-j] + a[j]);
        }
    }

    cout<<dp[N];
}