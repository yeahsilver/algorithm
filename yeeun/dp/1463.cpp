#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int dp[1000001];
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    int X;

    cin>>X;

    for(int i=4;i<=X;i++){
        
    }

    
}

// #define min(x,y) ((x)<(y)?(x):(y))

// int main(void){
//     int X,i;
//     int dp[1000001];

//     dp[0] = 0;
//     dp[1] = 0;

//     cin>>X;

//     for(i = 2; i<=X; i++){
//         dp[i] = dp[i-1]+1;
//         if(i % 2 == 0){
//                 dp[i] = min(dp[i],dp[i/2] + 1);

//         }
//         if(i % 3 == 0) {
//             dp[i]= min(dp[i],dp[i/3] + 1);
//         }
//     }

//     cout<<dp[i];

    // int num;
    // int dp[1000001];
    // cin>>num;
    // dp[1]=0;
    // dp[2]=1;
    // dp[3]=1;
    // for(int i = 4 ; i<=num; i++){
    //     if(i%2==0) dp[i] = dp[i/2];
    //     else if(i%2==0 &&i%3==1) dp[i]=min(dp[i/2],dp[i/3]+1);
    //     else if(i%3==0) dp[i]=dp[i/3];
    //     else if()

}