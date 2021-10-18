#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 11

int N, M;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<char> graph[MAX];

enum position {
    HOLE,
    WALL,
    GO,
    RED,
    BLUE,
    NLL
};

int checkPosition(int x, int y) {
    if(graph[x][y] == 'O') {
        return HOLE;
    }

    if(graph[x][y] == '#') {
        return WALL;
    }
    
    if(graph[x][y] == '.') {
        return GO;
    }

    if(graph[x][y] == 'R') {
        return RED;
    }

    if(graph[x][y] == 'B') {
        return BLUE;
    }

    return NLL;
} 

int bfs(int redX, int redY, int blueX, int blueY) {
    int count = 0;
    bool isOverTenTimes = false;

    queue<pair<int, int> > red_need_visit;
    queue<pair<int, int> > blue_need_visit;

    red_need_visit.push(make_pair(redX, redY));
    blue_need_visit.push(make_pair(blueX, blueY));

    while(1) {
        if(count > 10) {
            isOverTenTimes = true;
        }

        int currentRedX = red_need_visit.front().first;
        int currentRedY = red_need_visit.front().second;
        int currentBlueX = blue_need_visit.front().first;
        int currentBlueY = blue_need_visit.front().second;

        red_need_visit.pop();
        blue_need_visit.pop();

        for(int i = 0; i < 4; i++) {
            int nextRedX = currentRedX + dx[i];
            int nextRedY = currentRedY + dy[i];

            int nextBlueX = currentBlueX + dx[i];
            int nextBlueY = currentBlueY + dy[i];
            
            // blue check
            int blueCheck = checkPosition(nextBlueX, nextBlueY);
            cout << "check\n";
            cout << blueCheck << '\t';

            if(blueCheck == HOLE) {
                continue;
            }

            if(blueCheck == GO || blueCheck == RED || blueCheck == BLUE) {
                if(nextBlueX > 0 && nextBlueX <= N-1  && nextBlueY > 0 && nextBlueY <= M-1) {
                    blue_need_visit.push(make_pair(nextBlueX, nextBlueY));   
                }
            }

            // red check
            int redCheck = checkPosition(nextRedX, nextRedY);
            cout << redCheck << '\n';

            cout << nextRedX << '\t' << nextRedY << '\t' << nextBlueX << '\t' << nextBlueY << '\n';

            if(redCheck == HOLE) {
                break;
            }

            if(redCheck == GO||  redCheck == RED || redCheck == BLUE) {
                if(nextRedX > 0 && nextRedX <= N-1  && nextRedY > 0 && nextRedY <= M-1) {
                    red_need_visit.push(make_pair(nextRedX, nextRedY));   
                }
            }
        }
    
        count++;
    }

    return isOverTenTimes ? -1 : count;
}

int main(void) {
    cin >> N >> M;

    int redX, redY;
    int blueX, blueY;
    
    for(int i = 0; i  < N; i++) {
        for(int j = 0; j < M; j++) {
            char value;
            cin >> value;

            if(value == 'R') {
                redX = i;
                redY = j;

            } else if (value == 'B') {
                blueX = i;
                blueY = j;
            }

            graph[i].push_back(value);
        }
    }

    cout << bfs(redX, redY, blueX, blueY) << '\n';
}