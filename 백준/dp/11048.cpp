#include <iostream>

using namespace std;

#define MAX 1001

int Max(int a, int b, int c){
    int max = 0;
    if(a > max) max = a;
    if(b > max) max = b;
    if(c > max) max = c;

    return max;
}
int main(void){
    int N, M;
    int max = 0;
    int dp[MAX][MAX];

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int input;
            cin >> input;
            max = Max(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
            dp[i][j] = max + input;
        }
    }

    cout << dp[N][M]<<'\n';
}