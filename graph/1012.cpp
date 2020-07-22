#include <iostream>
#include <queue>
#include <cstring>

#define MAX 50

using namespace std;

bool bat[MAX][MAX];
bool visited[MAX][MAX];

int mX[4] = {-1, 0, 1, 0};
int mY[4] = {0, 1, 0, -1};

void BFS(int x, int y, int num){
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(x, y));
    visited[x][y] = true;

    while(!need_visit.empty()){
        int currentX = need_visit.front().first;
        int currentY = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++){
            int nX = currentX + mX[i];
            int nY = currentY + mY[i];

            if(nX >= 0 && nY >= 0 && nX < MAX && nY < MAX){
                if(!visited[nX][nY] && bat[nX][nY]){
                    need_visit.push(make_pair(nX, nY));
                    visited[nX][nY] = true;
                }
            }
        }
    }
}

int main(void){
    int test_case, garo, sero, num;
    int cnt = 0;
    
    cin >> test_case;

    for(int k = 0; k < test_case; k++){
        cin >> garo >> sero >> num;

        for(int i = 0; i < num; i++){
            int x, y;
            cin >> x >> y;
            bat[x][y] = true;
        }

        for(int i = 0; i < garo; i++){
            for(int j = 0; j < sero; j++){
                if(bat[i][j] && !visited[i][j]){
                    BFS(i,j, num);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

        memset(visited, false, sizeof(visited));
        memset(bat, false, sizeof(bat));
        cnt = 0;
    }
}