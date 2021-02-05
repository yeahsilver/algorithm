#include <iostream>
#include <cstring> 

using namespace std;

#define MAX 501

int routes[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;

long long dp[MAX][MAX];

int dfs(int x, int y) {
    if(x == N-1 && y == M-1) {
        return 1;
    }

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(routes[x][y] > routes[nx][ny]) {
                dp[x][y] = dp[x][y] + dfs(nx,ny);
            }
        }
    }

    return dp[x][y];
}

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> routes[i][j];
            dp[i][j] = -1;
        } 
    }
    
    cout << dfs(0, 0) << '\n';
}