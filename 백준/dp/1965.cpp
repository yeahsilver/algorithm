#include <iostream>

using namespace std;

#define MAX 1001

int main(void) {
    int N;
    cin >> N;
    
    int arr[MAX] = {};
    arr[0] = 0;

    int dp[MAX] = {};
    dp[0] = 0;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
            }
        }
    }

    int maxValue = 0;

    for(int i = 1; i <= N; i++) {
        if(maxValue < dp[i]) {
            maxValue = dp[i];
        }
    }

    cout << maxValue << '\n';
}