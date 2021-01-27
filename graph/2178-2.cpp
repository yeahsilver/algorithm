#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define MAX 101

int N, M;

int graph[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


void BFS(int x, int y) {
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(x, y));
    visited[x][y] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first;
        int cy = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(!visited[nx][ny] && graph[nx][ny] && nx >=1 && nx <= N && ny>=1 && ny <= M) {
                need_visit.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                graph[nx][ny] = graph[cx][cy]+1;
            }
        }
    }
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

    BFS(1,1);

    cout <<graph[N][M] << '\n';
}