#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

char grid[MAX][MAX];
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

            if(nX >= 0 && nY >= 0 && nX < num && nY < num){
                if(grid[nX][nY] == grid[x][y] && !visited[nX][nY]){
                    need_visit.push(make_pair(nX, nY));
                    visited[nX][nY] = true;
                }
            }
        }
    }
}

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    int cnt_normal = 0;
    int cnt_abnormal = 0;

    cin >> num;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(grid[i][j] && !visited[i][j]){
                BFS(i,j, num);
                cnt_normal++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(grid[i][j] && !visited[i][j]){
                if(grid[i][j] == 'G') grid[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(grid[i][j] && !visited[i][j]){
                BFS(i,j, num);
                cnt_abnormal++;
            }
        }
    }

    cout<<cnt_normal<<' '<<cnt_abnormal<<'\n';

}