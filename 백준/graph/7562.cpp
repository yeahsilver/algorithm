#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 301

int N;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs(int startX, int startY, int endX, int endY) {
    int minCount = __INT_MAX__;
    bool isVisited[MAX][MAX] = {false, };
    queue<pair< pair<int, int>, int > > need_visit;

    need_visit.push(make_pair(make_pair(startX, startY), 0));
    isVisited[startX][startY] = true;

    while(!need_visit.empty()) {
        
        int cx = need_visit.front().first.first;
        int cy = need_visit.front().first.second;
        int count = need_visit.front().second,first;

        need_visit.pop();

        if(cx == endX && cy == endY) {
            minCount = min(minCount, count);
        }

        for(int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || isVisited[nx][ny]) {
                continue;
            }

            need_visit.push(make_pair(make_pair(nx, ny), count+1));
            isVisited[nx][ny] = true;
        }
    }
    
    cout << minCount << '\n';
}

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        cin >> N;

        int startX, startY;
        int endX, endY;

        cin >> startX >> startY;
        cin >> endX >> endY;

        bfs(startX, startY, endX, endY);
    }
}