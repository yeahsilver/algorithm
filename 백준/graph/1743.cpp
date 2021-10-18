#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

int N, M, K;
int graph[MAX][MAX];
bool isVisited[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    int answer = 1;
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(x, y));
    isVisited[x][y] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first;
        int cy = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 0) {
                continue;
            }

            if(!isVisited[nx][ny]) {
                need_visit.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                answer++;
            }
        }
    }

    return answer;
}

int maxConnection() {
    int maxNum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!isVisited[i][j] && graph[i][j] == 1) {
                maxNum = max(maxNum,bfs(i, j));
            }
        }
    }
    return maxNum;
}

int main(void) {
    cin >> N >> M >> K;

    memset(graph, 0, sizeof(graph));
    memset(isVisited, false, sizeof(isVisited));

    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;

        graph[x-1][y-1] = 1;
    }   

    cout << maxConnection() << '\n';
}