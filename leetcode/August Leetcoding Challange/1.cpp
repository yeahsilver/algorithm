#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 501

class Solution {
public:
    int visited[MAX][MAX];
    int count, visitCount = 0;

    int largestIsland(vector<vector<int> >& grid) {
        int answer = 0;

        int n = grid.size();
        int m = grid[0].size();

        memset(visited, 0, sizeof(visited));

        for(int cx = 0; cx < n; cx++) {
            for(int cy = 0; cy < m; cy++) {

                if(grid[cx][cy] == 1) {
                    continue;
                }

                grid[cx][cy] = 1;

                count = 0;
                visitCount++;
                dfs(cx, cy, grid);
                
                answer = max(answer, count);

                grid[cx][cy] = 0;
            }
        }

        return answer == 0 ? n*m : answer;
    }

    void dfs(int x, int y, vector<vector<int> > &grid) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        if(visited[x][y] == visitCount) {
            return;
        }

        visited[x][y] = visitCount;
        count++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0|| nx > n-1 || ny > n-1) {
                continue;
            }

            if(visited[nx][ny] < visitCount && grid[nx][ny]) {
                dfs(nx, ny, grid);
            }
        }
    }
};

int main(void) {
    Solution solution;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(0);

    vector<int> v2;
    v2.push_back(0);
    v2.push_back(1);

    // vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(1);

    // vector<int> v2;
    // v2.push_back(1);
    // v2.push_back(1);

    // vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(0);
    // v1.push_back(1);

    // vector<int> v2;
    // v2.push_back(0);
    // v2.push_back(0);
    // v2.push_back(0);

    // vector<int> v3;
    // v3.push_back(0);
    // v3.push_back(1);
    // v3.push_back(1);

    vector<vector<int> > grid;
    grid.push_back(v1);
    grid.push_back(v2);
    // grid.push_back(v3);

    cout << solution.largestIsland(grid) << '\n';
}