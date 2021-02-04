#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10001

int main(void) {
    int num;
    cin >> num;

    int a[MAX] = {0, };
    int dp[MAX] = {0, };

    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }

    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for(int i = 3; i <= num; i++) {
        dp[i] = max(dp[i-2] + a[i], dp[i-3]+a[i-1]+a[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[num] << '\n';
}