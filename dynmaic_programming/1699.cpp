#include <iostream>
using namespace std;

int main(void){
    int N;
    int dp[100001] = {};

    cin>>N;

    for(int i = 1; i <= N;i++){
        for(int j = 1; j*j <= i; j++){
            if(dp[i] > dp[i - j*j] + 1 || dp[i] == 0){
                dp[i] = dp[i-j*j] + 1;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout<<dp[i]<<"\t";
    }


    cout<<"\n"<<dp[N];

}