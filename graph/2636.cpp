#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 101

bool visited[MAX][MAX];

int N, M;
int graph[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void BFS() {
    memset(visited,false, sizeof(visited));

    queue<pair<int,int> > need_visit;
    need_visit.push(make_pair(0,0));
    visited[0][0] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first;
        int cy = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if(!visited[nx][ny] && graph[nx][ny] == 0) { 
                need_visit.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    for(int i = 1; i < N-1; i++) {
        for(int j = 1; j < M-1; j++) {

            if(graph[i][j] == 0) {
                continue;
            }

            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = i + dy[k];

                if(visited[nx][ny]) {
                    graph[i][j] = 0;
                    break;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int cnt = 0;
    int time = 0;
    int last = 0;

    while(true) {
        int cheese = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] == 1) {
                    cheese++;
                }
            }
        }

        if(cheese == 0) {
            break;
        } else {
            last = cheese;
        }

        BFS();
        time++;
    }
    cout << time << '\n';
    cout << last << '\n';
}