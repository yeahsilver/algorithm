// 미완성
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 11
int graph[MAX][MAX] = {};
bool visited[MAX][MAX] = {};
int price[MAX][MAX] = {};

int mX[5] = {0,0,-1,1,0}; 
int mY[5] = {-1,1,0,0,0};
// 제자리에 있는 값까지 계산해주어야하기에 mX, mY에 0 추가.

int N;

bool isAvailable(int x, int y){ // 겹치는 영역 찾기.
    for(int i = 0; i < 5; i++){
        if(visited[x+mX[i]][y+mY[i]]){ // 영역이 겹치면
           return false;
        }
        return true; // 영역이 겹치지 않으면
    }
}

void DFS(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 5; i++){
        int nX = x + mX[i];
        int nY = y + mY[i];
        
        if(!graph[nX][nY] && !visited[nX][nY]){
           DFS(nX,nY);
           // 여기를 어떻게 채워야할지 모르겠오요...

        }
    }
}

int getPrice(int x, int y){
    int total  = 0;
    for(int i = 0; i < 5; i++){
        int nX = x + mX[i];
        int nY = y + mY[i];
        total += graph[nX][nY];
    }
    return total;
}

int main(void){
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j <N; j++){
            int G;
            cin >> G;
            graph[i][j] =  G;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            price[i][j] = getPrice(i,j);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] && !visited[i][j]){
                DFS(i,j);
            }
        }
    } 
}