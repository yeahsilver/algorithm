#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 101

// 상하좌우 좌표 정의
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isVisited[MAX][MAX];
int N, L, R;
vector<int> map[MAX];

void bfs(int x, int y) {
    vector<pair<int, int> > numbers; // 연결 요소에 대한 좌표를 저장하는 벡터 변수
    queue<pair<int, int> > need_visit;

    numbers.push_back(make_pair(x, y)); 
    need_visit.push(make_pair(x, y));

    isVisited[x][y] = true;

    while(!need_visit.empty()) {
        int cx = need_visit.front().first;
        int cy = need_visit.front().second;

        need_visit.pop();

        // 상하좌우를 탐색하여 방문하지 않은 인접 요소 찾기
        for(int i = 0; i < 4; i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) {
                continue;
            }

            // 국경선을 공유하는 조건 판별하기
            int distance;

            if(map[cx][cy] > map[nx][ny]) {
                distance = map[cx][cy] - map[nx][ny];

            } else {
               distance = map[nx][ny] - map[cx][cy]; 
            }

            if(distance < L || distance > R) {
                continue;
            }

            // 국경선을 공유 할 수 있다면 다음 나라의 좌표 저장
            if(!isVisited[nx][ny]) {
                need_visit.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                numbers.push_back(make_pair(nx,ny));
            }
        }
    }
    
    int sum = 0;
    int count = 0;

    // 국경선을 공유하는 나라의 좌표를 통해 각 나라별 인구수를 추출하여 sum 변수에 더함
    for(int i = 0; i < numbers.size(); i++) {
        int x = numbers[i].first;
        int y = numbers[i].second;

        sum += map[x][y];
        count++;
    }

    // 연합을 이루고 있는 각 칸의 인구수를 구함
    sum = sum/count;

    // 연합을 이루고 있는 국가의 좌표에 맞게 인구수를 새로 대입
    for(int i = 0; i < numbers.size(); i++) {
        int x = numbers[i].first;
        int y = numbers[i].second;

        map[x][y] = sum;
    }
}

void connection() {
    // 방문 여부 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            isVisited[i][j] = false;
        }
    }

    // 방문하지 않았으면 bfs로 넘어가 어떤 나라와 인접하여있는지 구함
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

    // 배열을 모두 순회하며 두 나라의 인구 차이가 L명 이상, R명 이하인지 체크
    // 만약 L명 이하, R명 이상이면 인구 이동이 한차례 더 이동해야한다는 것이기에, 
    // isFinished를 false로 대입하여 인구 이동이 더 일어날 수 있음을 나타내기

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
    
    // 입력 값 넣기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int value;
            cin >> value;
            map[i].push_back(value);
        }
    }

    int count = 0;

    // finish() 함수를 통해 인구 이동이 있는지 없는지 확인
    while(!finish()) {
        // 만약 인구 이동이 있으면 연결 요소를 찾아야함
        connection();
        count++;
    }

    cout << count << '\n';
}