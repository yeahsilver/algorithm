#include <iostream>
using namespace std;

int main(void){
    int N;
    int a[100010] = {};
    int dp[100010] = {};
    int max;

    cin>>N;

    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= N; i++){
        if(a[i] < dp[i-1] + a[i]){
            dp[i] = dp[i-1] + a[i];
        } else {
            dp[i] = a[i];
        }
    }   

    max = dp[1];
    for(int i = 2; i <= N; i++){
        if(max<dp[i]) max = dp[i];
    }

    cout<<max;   
}