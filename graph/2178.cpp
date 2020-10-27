#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 101
#define P pair<int, int> 

using namespace std;

int N, M;
int maze[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y){
    queue<P> need_visit;
    need_visit.push(make_pair(x,y));

    while(!need_visit.empty()){
        P now = need_visit.front();
        need_visit.pop();

        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx >=0 && ny >= 0 && nx < N && ny < M){
                if(maze[nx][ny] == 1){
                    need_visit.push(make_pair(nx,ny));
                    maze[nx][ny] = maze[now.first][now.second]+1;
                }
            }
        }
    }
}

int main(void){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    BFS(0,0);

    cout << maze[N-1][M-1];
}