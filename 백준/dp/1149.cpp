#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int dp[MAX][MAX];   
int color[MAX][MAX];

int main(void){ 
    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }

    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for(int i = 1; i < num; i++) {
        for(int j = 0; j < 3; j++) {
            if (j == 0) { // 빨강일 경우
                dp[i][j] = min(dp[i-1][1] + color[i][j] , dp[i-1][2] + color[i][j]);
            } else if (j == 1) { // 초록일 경우
                dp[i][j] = min(dp[i-1][0] + color[i][j] , dp[i-1][2] + color[i][j]);
            } else { // 파랑일 경우
                dp[i][j] = min(dp[i-1][0] + color[i][j] , dp[i-1][1] + color[i][j]);
            }
        }
    }

    int minValue = __INT_MAX__;
    for(int i = 0; i < 3; i++) {
        if(minValue > dp[num-1][i]) {
            minValue = dp[num-1][i];
        }
    }

    cout << minValue << '\n';
}