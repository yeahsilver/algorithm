#include <iostream>

using namespace std;

#define MAX 1000001

int dp[MAX] = {0,};

int main(void){
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i]%=15746;
    }

    cout << dp[N] << '\n';

}