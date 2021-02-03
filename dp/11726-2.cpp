#include <iostream>
using namespace std;

#define MAX 1000

int dp[MAX];

int main(void) {
    int num;
    cin >> num;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= num; i++) {
        dp[i] = (dp[i-1]+ dp[i-2]) % 10007;
    }


    cout << dp[num];
}