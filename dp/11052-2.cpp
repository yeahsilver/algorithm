#include <iostream>
using namespace std;

#define MAX 1001

int a[MAX];
int dp[MAX];

int main(void) {
    int num;
    cin >> num;

    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }

    for(int i = 1 ; i <= num; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j] + a[j]);
        }
    }

    cout << dp[num] << '\n';
}