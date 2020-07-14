#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101

int N, M, K;
int cnt = 0; // 넓이 영역
bool graph[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};

int mX[4] = {0,0,-1,1};
int mY[4] = {-1,1,0,0};

void DFS(int x, int y){
    visited[x][y] = true;
    cnt++; // 칸의 개수 (정사각형이기에 넓이로도 사용 가능.)
    for(int i = 0; i <4; i ++){
        int nX = x + mX[i];
        int nY = y + mY[i];
        if(nX < 0 || nY <0 || nX >=N || nY >= M){ // 범위를 넘어가는 경우
            continue;
        }
            
        if(!graph[nX][nY] && !visited[nX][nY]){
           DFS(nX,nY);
        }
    }
}

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> v;

    cin >> N >> M >> K;
    
    while(K--){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        for(int i = x1; i <x2; i++){
            for(int j = y1; j <y2; j++){
                visited[i][j] = true;
                graph[i][j] = true;
            }
        }
    }

    for(int i =0 ; i< N; i++){
        for(int j = 0; j < M; j++){
            if(!graph[i][j] && !visited[i][j]){
                cnt = 0;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(int i = 0; i <v.size(); i++){
        cout<<v[i]<<" ";
    }
}
