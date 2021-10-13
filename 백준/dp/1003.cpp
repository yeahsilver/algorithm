#include <iostream>

using namespace std;

#define MAX 41

int fibonacci(int num, int* dp) {
    if(num == 0 || num == 1) {
        return dp[num];
    }
    if(dp[num] != 0) {
        return dp[num];
    } else {
        return dp[num] = fibonacci(num-1, dp) + fibonacci(num-2, dp);
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    while(test_case--) {
        int num;
        cin >> num;

        int dp[MAX] = {1,1};
        fibonacci(num, dp);

        if(num == 0) {
            cout << 1 << ' ' << 0 << '\n';
        } else if (num == 1) {
            cout << 0 << ' ' << 1 << '\n';
        } else {
            cout << dp[num-2] << ' ' << dp[num-1] << '\n';
        }
    }
}