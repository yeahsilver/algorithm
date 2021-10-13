#include <iostream>

using namespace std;

#define MAX 1000001

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int test_case;
    cin >> test_case;

    long long dp[MAX] = {0,};

    for(int i = 1; i < MAX; i++) {
        for(int j = 1; i*j < MAX; j++) {
            dp[i*j]+=i;
        }
    }

    for(int i = 1; i < MAX; i++) {
        dp[i] += dp[i-1];
    }

    while(test_case--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }   

    return 0;
}