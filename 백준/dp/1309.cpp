#include <iostream>

using namespace std;

#define MAX 100001

int main(void) {
    int N;
    cin >> N;
    
    int dp[MAX] = {0, };
    
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 7;

    for(int i = 3; i <= N; i++) {
        dp[i] = (dp[i-2]+ (2*dp[i-1]))%9901;
    }   

    cout << dp[N];
}