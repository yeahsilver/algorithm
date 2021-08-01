#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 101

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isVisited[MAX][MAX];
int N, L, R;
vector<int> map[MAX];

void bfs(int x, int y) {
    vector<pair<int, int> > numbers;

    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(x, y));
    numbers.push_back(make_pair(x, y));

    isVisited[x][y] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first;
        int cy = need_visit.front().second;

        need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) {
                continue;
            }

            int distance;

            if(map[cx][cy] > map[nx][ny]) {
                distance = map[cx][cy] - map[nx][ny];

            } else {
               distance = map[nx][ny] - map[cx][cy]; 
            }

            if(distance < L || distance > R) {
                continue;
            } 
            

            // cout << "distance\n";
            // cout << cx << '\t' << cy << '\n';
            // cout << nx << '\t' << ny << '\n';

            if(!isVisited[nx][ny]) {
                need_visit.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                numbers.push_back(make_pair(nx,ny));
            }
        }
    }

    int sum = 0;
    int count = 0;
    
    vector<pair<int, int> > numbers_copy;

    for(int i = 0; i < numbers.size(); i++) {
        int x = numbers[i].first;
        int y = numbers[i].second;

        sum += map[x][y];
        count++;
    }

    sum = sum/count;

    for(int i = 0; i < numbers.size(); i++) {
        int x = numbers[i].first;
        int y = numbers[i].second;

        map[x][y] = sum;
    }
}

void connection() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            isVisited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!isVisited[i][j]) {
                bfs(i, j);
            }
        }
    }
}

bool finish() {
    bool isFinished = true;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) {
                    continue;
                }

                int distance;

                if(map[i][j] > map[nx][ny]) {
                    distance = map[i][j] - map[nx][ny];

                } else {
                    distance = map[nx][ny] - map[i][j]; 
                }

                if(distance < L || distance > R) {
                    continue;
                } 

                isFinished = false;
            }
        }
    }

    return isFinished;
}

int main(void) {
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int value;
            cin >> value;
            map[i].push_back(value);
        }
    }

    int count = 0;


    while(!finish()) {
        connection();
        count++;
    }

    cout << count << '\n';
}