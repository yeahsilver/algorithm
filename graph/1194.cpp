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
    queue<pair<pair<int, int>, pair<int, int> > > need_visit;
    bool visited[MAX][MAX][64] = {false, };

    need_visit.push(make_pair(make_pair(x, y), make_pair(0, 0)));
    visited[x][y][0] = true;

    while(!need_visit.empty()) {

        int cx = need_visit.front().first.first;
        int cy = need_visit.front().first.second;

        int count = need_visit.front().second.first;
        int key = need_visit.front().second.second;

        need_visit.pop();

        if(maze[cx][cy] == '1') {
            return count;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M || maze[nx][ny] == '#' || visited[nx][ny][key]) {
                continue;
            }
            
            if (maze[nx][ny] == '.' || maze[nx][ny] == '1' || maze[nx][ny] == '0') {
                visited[nx][ny][key] = true;
                need_visit.push(make_pair(make_pair(nx, ny), make_pair(count+1, key)));

            } else if(maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') {
                int check = key | (1 << (maze[nx][ny]-97));

                if(!visited[nx][ny][check]) {
                    visited[nx][ny][key] = true;
                    visited[nx][ny][check] = true;
                    need_visit.push(make_pair(make_pair(nx, ny), make_pair(count+1, check)));
                }
                

            } else if(maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F') {

                if(key & (1 << (maze[nx][y]-65))) {
                    visited[nx][ny][key] = true;
                    need_visit.push(make_pair(make_pair(nx, ny), make_pair(count+1, key)));
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