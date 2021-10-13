#include <iostream>

using namespace std;

#define MAX 500

int dp[MAX][MAX];
int a[MAX][MAX];

int main(void) {
    int num;
    cin >> num;

    int indexCnt = 0;

    while(indexCnt < num) {
        for(int i = 0; i <= indexCnt; i++) {
            cin >> a[indexCnt][i];
        }
        indexCnt++;
    }

    dp[0][0] = a[0][0];

    for(int i = 1; i < num; i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j]+a[i][j] , dp[i-1][j-1] + a[i][j]);
            }
        }
    }

    int maxCnt = 0;
    for(int i = 0; i < num; i++) {
       if(maxCnt < dp[num-1][i]) {
           maxCnt = dp[num-1][i];
       }
    }

    cout << maxCnt << '\n';
}