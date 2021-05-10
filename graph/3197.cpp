// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// #define MAX 1501
// #define for(i, start, end) for(int i = start; i < end; i++)


// int column, row;

// string map[MAX];

// vector<pair<int, int> > water;
// vector<pair<int, int> > swan;

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// void swan_bfs() {
//     queue<pair<int, int> > need_visit;

//     bool visited[MAX][MAX] = {0, };

//     need_visit.push(swan[0]);
//     visited[swan[0].first][swan[0].second];

//     int day = 0;

//     while(1) {
//         queue<pair<int, int> > next;

//         bool flag = false;

//         while(!need_visit.empty()) {
//             int currentX = need_visit.front().first;
//             int currentY = need_visit.front().second;

//             need_visit.pop();

//             if(swan[1].first == currentX && swan[1].second == currentY) {
//                 flag = true;
//                 break;
//             }

//             for(i, 0, 4) {
//                 int nextX = currentX + dx[i];
//                 int nextY = currentY + dy[i];

//                 if(nextX < 0 || nextX >= column || nextY < 0 || nextY >= row) {
//                     continue;
//                 }

//                 visited[nextX][nextY] = true;

//                 if(map[nextX][nextY] == 'X') {
//                     next.push(make_pair(nextX, nextY));
//                     continue;
//                 }

//                 need_visit.push(make_pair(nextX, nextY));
//             }

//             if(flag) {
                
//             }

            
//         }
//     }
// }

// int main(void) {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     cin >> column >> row;

//     for(i, 0, column) {
//        cin >> map[i];

//        for(j, 0, row) {
//            if(map[i][j] == 'L') {
//                swan.push_back(make_pair(i, j));
//            }

//            if(map[i][j] == '.' || map[i][j] == 'L') {
//                water.push_back(make_pair(i, j));
//            }
//        }
//     }

//     swan_bfs();
// }