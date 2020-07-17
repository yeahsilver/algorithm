// 미완성
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 50

pair<int, int> visited[MAX][MAX];
pair<int, int> info[MAX][MAX];

int chess[MAX][MAX] = {0, };

int cX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int cY[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

/*
    BFS
    1. 첫 노드 cnt 1 증가 & 첫 노드 push
    2. front().first / front().second 값 저장
    3. front() 위치를 기반으로 움직이는 위치 설정
    4. 마알의 수 < cnt 수이면 continue로 BFS 빠져나오기.
*/

void BFS(int width, int height, int num){
    queue<pair<int, int> > q;

    q.push(make_pair(width, height));

    visited[width][height].first++;
    info[width][height].first = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 8; i++){
            int nX = x + cX[i];
            int nY = y + cY[i];

            if(nX < 1 || nX > width || nY < 1 || nY > height) continue;
            else if(info[nX][nY].first == 0){
                q.push(make_pair(nX, nY));
                info[nX][nY].first = 1;
                info[nX][nY].second = info[x][y].second + 1;
                visited[nX][nY].first++;

                if(info[nX][nY].second % num != 0){ // k-마알 중 k가 아닐 경우  
                    visited[nX][nY].second += (info[nX][nY].second / num) + 1;
                } else {
                    visited[nX][nY].second += (info[nX][nY].second / num);
                }
            }
        }
    }
}

/* 
    main
    1. width, height 값을 받음.
    2. .을 int형으로 변환
    3. BFS를 실행할 때 마다 cnt를 1씩 증가
    4. visited[i][j] == cnt 일 경우 최소값을 구한다. 
    4-1. 조건에 만족하지 않으면 -1 출력
*/

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char arr[MAX][MAX] = {0, };

    int width, height;
    int cnt = 0;
    int minimum = 1000000000;

    cin >> width >> height;

    for(int i = 1; i <= width; i++){
        string str;
        cin >> str;

        for(int j = 0; j < str.size(); j++){
            chess[i][j] = str[j];
        }
    }
    for(int i = 0; i < width; i ++){
        for(int j = 0; j <height; j++){
            if(chess[i][j] != '.'){
                cnt++;
                int num = chess[i][j] - '0';
                BFS(i, j, num);
            }
            fill(&info[0][0], &info[0][0] + MAX * MAX, make_pair(0,0));
        }
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(visited[i][j].first == cnt){
                minimum = min(minimum, visited[i][j].second);
            } else {
                continue;
            }
        }
    }
    if(minimum != 1000000000){
        cout << minimum;
    } else {
        cout << -1;
    }
}

