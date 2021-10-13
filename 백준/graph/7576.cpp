#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

bool visited[MAX][MAX];

int N, M;
int graph[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int cnt = 0;

queue<pair<pair<int, int>, int> > need_visit;

void BFS() {
    while(!need_visit.empty()) {
        int cx = need_visit.front().first.first;
        int cy = need_visit.front().first.second;
        cnt = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i]; 
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if(!visited[nx][ny] && graph[nx][ny] == 0) {
                visited[nx][ny] = true;
                need_visit.push(make_pair(make_pair(nx,ny),cnt+1));
            }
        }
    }
}

int main(void) {
    memset(visited, false, sizeof(visited));
    cin >> M >> N;  

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }  

    bool isWhole = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 0) {
                isWhole = 0;
            }
        }
    }

    if(!isWhole) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] == 1) {
                    visited[i][j] = true;
                    need_visit.push(make_pair(make_pair(i, j), cnt));
                }
            }
        }

        BFS();

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!visited[i][j] && graph[i][j] == 0) {
                    cnt = -1;
                }
            }
        }
        cout << cnt  << '\n';
    } else {
        cout << 0 << '\n';
    }   
}
