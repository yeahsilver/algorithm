#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 26

using namespace std;

vector<int> graph[MAX];

int N;
int cnt = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool visited[MAX][MAX] = {false, };
int house_num[MAX * MAX] = {0, };

void BFS(int x, int y) {
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(x, y));
    visited[x][y] = true;
    house_num[cnt]++;

    while(!need_visit.empty()) {
        int cX = need_visit.front().first;
        int cY = need_visit.front().second;

        need_visit.pop();
       
        for(int i = 0; i < 4; i++) {
            int nX = cX + dx[i];
            int nY = cY + dy[i];

            if(nX >= 0 && nY >= 0 && nX < N && nY < N) {
                if(graph[nX][nY] && !visited[nX][nY]) {
                    need_visit.push(make_pair(nX, nY));
                    visited[nX][nY] = true;
                    house_num[cnt]++;
                }
            }
        }
    }
}

void find_connect_factor() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && graph[i][j]) {
                BFS(i, j);
                cnt++;
            }
        }
    }
}

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            graph[i].push_back(s[j]-'0');
        }
    }

    find_connect_factor();

    cout << cnt << '\n';

    sort(house_num, house_num+cnt);
    
    for(int i = 0; i < cnt; i++) {
        cout << house_num[i] << '\n';
    }
}