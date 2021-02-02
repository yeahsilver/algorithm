#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10001

int dp[MAX] = {0, };

int main(void) {
    int n;
    cin >> n;

    int * stairs = new int[n+1];

    for(int i = 1;  i <= n; i++) {
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[2] + stairs[3], stairs[1] + stairs[3]);

    for(int i = 4; i <= n; i++) {
       dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i]);
    }
 
    cout << dp[n] << '\n';
}