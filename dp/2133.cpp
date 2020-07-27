#include <iostream>
using namespace std;

int main(void){
    int N;
    int dp[31] = {1,0,3};

    cin>>N;
        
    for(int i = 4; i <= N; i+=2){
        dp[i] = dp[i-2] * 3;
            
        for(int j = 4; j<=i; j+=2){
            dp[i]+= dp[i-j] * 2;
        }
    }


    cout<<dp[N];
}