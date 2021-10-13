#include <iostream>
using namespace std;

#define MAX 101

long long dp[MAX][MAX];
int route[MAX][MAX];

int main(void) {
    int num; 
    cin >> num;

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= num; j++) {
            cin >> route[i][j];
        }
    }

    dp[1][1] = 1;

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= num; j++) {
            if(dp[i][j] == 0 || (i == num && j == num)) {
                continue;
            }

            int direction = route[i][j];
            int down = i + direction;
            int right = j + direction; 

            if(down < num + 1) {
                dp[down][j] = dp[down][j] + dp[i][j];
            }

            if(right < num + 1) {
                dp[i][right] = dp[i][right] + dp[i][j];
            }
        }
    }
     cout << dp[num][num] << '\n';
}