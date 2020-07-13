// 미완성
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50

bool map[MAX][MAX];
bool visited[MAX][MAX];

int mX[8] = { 0 -1 -1 -1, 0, 1, 1, 1 };
int mY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void BFS(int height, int width){
    queue<pair<bool, bool> > need_visit;

    visited[height][width] = true;
    need_visit.push(make_pair(height, width));

    while(!need_visit.empty()){
        int x = need_visit.front().first;
        int y = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + mX[i];
            int ny = y + mY[i];

            if(nx >= 0 && ny >= 0 && nx < MAX && ny < MAX){
                if(map[nx][ny] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    need_visit.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, height;

    while(1){
        cin >> width >> height;

        if(width == 0 && height == 0){
            break;
        }

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                map[i][j] = 0;
            }
        }

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                cin>>map[i][j];
            }
        }

        int cnt = 0;

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(map[i][j] && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        cout<<cnt<<'\n';

        memset(map, false, sizeof(map));
        memset(visited, false, sizeof(visited));
        cnt = 0;
    }
    return 0;
}