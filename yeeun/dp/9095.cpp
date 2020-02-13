#include <iostream>
using namespace std;

int main(void){
    int N,num;



    cin>>num;
    
    for (int k = 0; k<num; k++){
        cin>>N;

        int dp[11]={0};

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4; i<=N; i++){
            

            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout<<dp[N]<<"\n";
    }
}