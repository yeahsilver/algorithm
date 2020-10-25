#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 101

int N, M;
int maze[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
    queue<pair<int,int> > need_visit;
    need_visit.push(make_pair(1,1));

    while(!need_visit.empty()){
        pair<int, int> now = need_visit.front();
        need_visit.pop();

        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M && maze[nx][ny] == 1){
                need_visit.push(make_pair(nx, ny));
                maze[nx][ny] = maze[now.first][now.second] + 1;
            }
        }
    }
}

int main(void){
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    BFS();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
           cout << maze[i][j] << '\t';
        }
        cout << '\n';
    }
    
    cout << maze[N][M];
}