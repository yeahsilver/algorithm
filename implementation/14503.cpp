#include <iostream>
#include <vector>

using namespace std;

#define MAX 51

enum directions {
    NORTH = 1,
    EAST, 
    SOUTH,
    WEST,
};

// 북 -> 서 -> 남 -> 동 순서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
    // 1. map에 값 넣기
    vector<int> map[MAX];

    int N, M;
    cin >> N >> M;
    
    int r, c, d;
    cin >> r >> c >> d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int value;
            cin >> value;
            map[i].push_back(value);
        }
    }

    c = map[0].size()-1 - c;

    int count = 1;

    // 2. while문 돌면서 청소 방향 체크
    while(1) {
        // 탈출 조건
        // 상하좌우가 청소가 되었거나 벽이고 후진 하려고 하는 방향의 위치가 벽이면 종료
        int north = map[r+dx[0]][c+dy[0]];
        int west = map[r+dx[1]][c+dy[1]];
        int south = map[r+dx[2]][c+dy[2]];
        int east = map[r+dx[3]][c+dy[3]];
        int back;

        if(d == NORTH) {
            back = south;
        } else if (d == WEST) {
            back = east;
        } else if (d == SOUTH) {
            back = north;
        } else if (d == EAST) {
            back = west;
        }

        if((north == 1 || north == -1) && (west == 1 || west == -1) && (south == 1 || south == -1) && (east == 1 || east == -1) && back == 1) {
            break;
        }

        // 3. 위치 접근 후 청소
        if(map[r][c] == 0) {
            map[r][c] = -1;
        }

        // 4. 왼쪽으로 회전하여 청소가 되지 않은 부분으로 이동
        int i;
        if(d == NORTH) {
            i = 1;
        } else if (d == WEST) {
            i = 2;
        } else if (d == SOUTH) {
            i = 3;
        } else if (d == EAST) {
            i = 0;
        }

        bool isAllClean = false;

        for(int k = 0; k < 4; k++) {
           if(map[r+dx[i%3]][c+dy[i%3]] == 1 || map[r+dx[i%3]][c+dy[i%3]] == -1) {
               r += dx[i%3];
               c += dy[i%3];
               break;
            }
            i++;

            // 네 방향이 모두 청소가 되어있거나, 벽인 경우에는 바라보는 방향을 유지한 채로 한 칸 후진함
            if (k == 3) {
                if(d == NORTH) {
                    r += dx[1];
                    c += dy[1];
                } else if (d == WEST) {
                    r += dx[2];
                    c += dy[2];
                } else if (d == SOUTH) {
                    r += dx[3];
                    c += dy[3];
                } else if (d == EAST) {
                    r += dx[0];
                    c += dy[0];
                }
            }
        }

        // 후진 하려고 하는 곳이 벽이라면 종료 (벽인 경우 == 1, 청소 한 경우: -1)
        if(map[r][c] == 1) {
            break;
        }


        count++;
    }

    cout << count << '\n';
}