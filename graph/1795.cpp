#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50

int chess[MAX][MAX];
bool visited[MAX][MAX];

int cX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int cY[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int BFS(int width, int height){
    int cnt = 0;
    queue<pair<int, int> > need_visit;

    need_visit.push(make_pair(width, height));
    visited[width][height] = true;

    while(!need_visit.empty()){
        int x = need_visit.front().first;
        int y = need_visit.front().second;

        need_visit.pop();
        for(int i = 0; i < 8; i++){
            int nX = x + cX[i];
            int nY = y + cY[i];

            if(nX>=0 && nY >= 0 && nX < MAX && nY < MAX){
                if(chess[nX][nY] && !visited[nX][nY]){
                    need_visit.push(make_pair(nX, nY));
                    visited[nX][nY] = true;
                }
            }
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int width, height;
    int min_num = __INT_MAX__;

    cin >>width>>height;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            char input ;
            cin>> input;
            if(input!='.'){
                int num = input - '0';
                chess[i][j] = num;
            } else {
                chess[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            BFS(i, j);

        }
    }
}