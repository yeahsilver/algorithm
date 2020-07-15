#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

/* 
    MAX: max 값(50) 저장
    map: 바다인지 땅인지 저장해주는 배열
    visited: 해당 공간을 방문했는지 체크해주는 배열
    mX / mY: 상 하 좌 우 대각선 위치를 저장해주는 배열
*/

#define MAX 50

bool map[MAX][MAX];
bool visited[MAX][MAX];

int mX[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int mY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void BFS(int height, int width){
    // 1. 방문해야할 위치를 저장 (배열의 원소별로 위치를 저장하는 것이기에, pair 사용)
    queue<pair<int, int> > need_visit;

    // 2. 처음 받은 height와 width를 need_visit에 저장
    need_visit.push(make_pair(height, width));
    // 3. need_visit의 첫 원소 == 방문할 원소이기에 visited에 현재 위치 저장
    visited[height][width] = true;

    // 4. 필요한 위치를 모두 방문 하였을 경우 종료
    while(!need_visit.empty()){
        // 5. 처음 위치를 저장
        int x = need_visit.front().first;
        int y = need_visit.front().second;

        //6.  need_visit에서 pop == 방문한 공간을 pop
        need_visit.pop();

        // 7. 상 하 좌 우 모두 따져야하기 때문에 8번 반복문을 돌려 조건 확인
        for(int i = 0; i < 8; i++){
            int nx = x + mX[i];
            int ny = y + mY[i];

            // 조건) 이동한 곳이 땅이고, 아직 그 땅을 방문하지 않았을 경우 
            // --> 후에 방문해야하기에 need_visit에 원소를 저장해 준 뒤, 해당 방문 요소를 true로 변환
            if(nx >= 0 && ny >= 0 && nx < MAX && ny < MAX){
                if(map[nx][ny] && !visited[nx][ny]){
                    need_visit.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(void){
    // 입출력 시간 단축 메소드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 너비와 높이 저장 변수 생성
    int width, height;

    // 2. 무한 루프 실행
    while(1){
        cin >> width >> height;

        //  3. 0 0 을 받을 경우 종료
        if(width == 0 && height == 0){
            break;
        }

        // 4. map 배열 초기화 
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                map[i][j] = 0;
            }
        }

        // 5. map 배열 정보 저장
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                cin>>map[i][j];
            }
        }

        int cnt = 0;

        // 6. BFS가 새로 실행될 때 마다 cnt를 1씩 증가 시킴.
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(map[i][j] && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        // 7. cnt 출력
        cout<<cnt<<'\n';

        // 8. 배열 초기화 
        // 이유) 무한 반복을 돌기 떄문에 
        memset(map, false, sizeof(map));
        memset(visited, false, sizeof(visited));
        cnt = 0;
    }
    return 0;
}