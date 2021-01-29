#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101

int N, M, K;
int cnt = 0; // 넓이 영역
bool graph[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void DFS(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny <0 || nx >= N || ny >= M){
            continue;
        }
            
        if(!graph[nx][ny] && !visited[nx][ny]){
           DFS(nx,ny);
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> area;

    cin >> N >> M >> K;
    
    while(K--){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                visited[i][j] = true;
                graph[i][j] = true;
            }
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!graph[i][j] && !visited[i][j]){
                cnt = 0;
                DFS(i,j);
                area.push_back(cnt);
            }
        }
    }

    sort(area.begin(),area.end());

    cout << area.size() << '\n';
    
    for(int i = 0; i <area.size(); i++){
        cout << area[i] << ' ';
    }
}

