#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 1001

bool visited[MAX][MAX][2];

int N, M;
int cnt = 0;
int graph[MAX][MAX];


int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int BFS(int x, int y) {
    queue<pair<pair<int, int>, pair<int, int> > > need_visit;
    need_visit.push(make_pair(make_pair(x, y), make_pair(1,1)));
    visited[x][y][1] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first.first;
        int cy = need_visit.front().first.second;
        int wall = need_visit.front().second.first;
        int cnt = need_visit.front().second.second;

        need_visit.pop();

        if(cx == N && cy == M) {
            return cnt;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }

            if(!visited[nx][ny][wall] && graph[nx][ny] == 0) {
                need_visit.push(make_pair(make_pair(nx, ny), make_pair(wall, cnt+1)));
                visited[nx][ny][wall] = true;
            }

            if(graph[nx][ny] == 1 && wall == 1) {
                need_visit.push(make_pair(make_pair(nx, ny), make_pair(wall-1, cnt+1)));
                visited[nx][ny][wall] = true;
            }
        }
    }
    return -1;
}

int main(void) {
    memset(visited, false, sizeof(visited));
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= M; j++) {
            graph[i][j] = s[j-1] - '0';
        }
    }

    cout << BFS(1,1) << '\n';
}