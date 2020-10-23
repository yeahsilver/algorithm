#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

bool visited[26];
char board[MAX][MAX];
int R, C, maxCount;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void DFS(int x, int y, int cnt){
    // 최대 칸 수를 출력하기 위해 max() 사용
    maxCount = max(maxCount, cnt);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < R && ny < C){
            int next = board[nx][ny];
            if(!visited[next-'A']){
                visited[next-'A'] = true;
                DFS(nx, ny,cnt+1);
                // 말이 지날 수 있는 경로를 모두 탐색해야하기에 재귀가 탈출되면서 false가 되어야 정상적인 값 계산 가능
                visited[next-'A'] = false;
            }
        }
    }
}

int main(void){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    
    visited[board[0][0]-'A'] = true;
    DFS(0,0,1);

    cout << maxCount << '\n';
}