#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

/*
    - .: 빈 곳
    #: 절대 이동 불가
    a-f: 열쇠
    A-F: a-f에 대응하는 열쇠를 가지고 있으면 이동 가능
    0: 현재 위치
    1: 출구
*/

char maze[MAX][MAX];

int N, M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int x, int y) {
    priority_queue<pair<int, int> > need_visit;
    bool visited[MAX][MAX] = {false, };

    vector<char> keys;

    need_visit.push(make_pair(x, y));
    visited[x][y] = true;

    int count = 0;

    while(!need_visit.empty()) {

        int cx = need_visit.top().first;
        int cy = need_visit.top().second;

        need_visit.pop();

        bool isCheck = false;

        if(maze[nx][ny] == 1) {
            return count;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M ) {
                continue;
            }

            if(maze[nx][ny] == '#' || maze[nx][ny]) {
                continue;
            }
            
            if (maze[nx][ny] == '.' || maze[nx][ny] == '1' || maze[nx][ny] == '0' || maze[nx][ny] == '1') {
                need_visit.push(make_pair(nx, ny));
                count++;

            } else if(maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') {
                keys.push_back(maze[nx][ny]);
                need_visit.push(make_pair(nx, ny));
                count++;

            } else if(maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F') {
                for (char key: keys) {
                    if(key == maze[nx][ny]-32) {
                        need_visit.push(make_pair(nx, ny));
                        count++;
                    }
                }
            } 
        }
    }

    return -1;
}

int main(void) {
    cin >> N >> M;

    int px = 0, py = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char value;
            cin >> value;

            maze[i][j] = value;

            if(maze[i][j] == 0) {
                px = i;
                py = j;
            }
        }
    }

    cout << BFS(px, py) << '\n';
}