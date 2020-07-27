#include <iostream>
using namespace std;

int main(void){
    int N;
    int max = 0;
    int a[1001] = {};
    int dp[1001] = {};

    cin>>N;
    
    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j] && dp[i] < dp[j] + a[i]){
                dp[i] = dp[j] + a[i];
            }
        }
    }

    for(int i = 0; i <= N; i++){
        if(dp[i] > max) max = dp[i];
    }
    cout<<max;
}