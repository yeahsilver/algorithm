#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 101

bool visited[MAX][MAX][MAX];

int N, M, H;
int graph[MAX][MAX][MAX];

int dx[6] = {0, 1, 0, -1, 0};
int dy[6] = {-1, 0, 1, 0, 0};
int b[6] = {0, 0, 0, 0, -1, 1};

int cnt = 0;

queue<pair<pair<int, int>, pair<int, int> > > need_visit;

void BFS() {
    while(!need_visit.empty()) {
        int cx = need_visit.front().first.first;
        int cy = need_visit.front().first.second;
        int box = need_visit.front().second.first;
        cnt = need_visit.front().second.second;

        need_visit.pop();

        for(int i = 0; i < 6; i++) {
            int nx = cx + dx[i]; 
            int ny = cy + dy[i];
            int nb = box + b[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nb < 0 || nb >= H) {
                    continue;
            }

            if(!visited[nb][nx][ny] && graph[nb][nx][ny]== 0) {
                visited[nb][nx][ny] = true;
                need_visit.push(make_pair(make_pair(nx,ny),make_pair(nb, cnt+1)));
            }
        }
    }
}

int main(void) {
    memset(visited, false, sizeof(visited));
    cin >> M >> N >> H;  

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
           for(int k = 0; k < M; k++) {
                cin >> graph[i][j][k];
           }
        }
    }  


    bool isWhole = 1;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
           for(int k = 0; k < M; k++) {
                if(graph[i][j][k] == 0) {
                    isWhole = 0;
                }
            }
        }
    }  

    if(!isWhole) {
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < M; k++) {
                    if(graph[i][j][k] == 1) {
                        visited[i][j][k] = true;
                        need_visit.push(make_pair(make_pair(j, k), make_pair(i, 0)));
                    }
                }
            }
        }

        BFS();

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < M; k++) {
                    if(!visited[i][j][k] && graph[i][j][k] == 0) {
                        cnt = -1;
                    }
                }
            }
        }
        cout << cnt  << '\n';
    } else {
        cout << 0 << '\n';
    }   
}
