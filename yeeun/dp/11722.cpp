#include <iostream>
using namespace std;

int main(void){
    int N;
    int min = 0;
    int a[1001] = {};
    int dp[1001] = {};

    cin>>N;

    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }

     for(int i = 1; i <= N;i++){
            dp[i] = 1;
            for(int j = 0; j < i;j++){
                if(a[i] < a[j] && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
            }
        }

    for(int i = 1; i <= N; i++){
        if(dp[i] > min) min = dp[i];
    }

    cout<<min;
}