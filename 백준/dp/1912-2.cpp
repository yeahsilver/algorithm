#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int main(void) {
    int a[MAX];
    int dp[MAX];

    int num; 
    cin >> num;

    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= num; i++) {
        dp[i] = max(dp[i-1]+a[i],a[i]);
    }

    int maxNum = dp[1];

    for(int i = 2; i <= num; i++) {
        if(maxNum < dp[i]) {
            maxNum = dp[i];
        }
    }

    cout << maxNum << '\n';
}