#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 501

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        bool isAllOne = true;

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue;

                isAllOne = false;

                grid[i][j] = 1;
                count = BFS(i, j, grid);
                grid[i][j] = 0;
                
            }
        }
    }

    int connection(int x, int y, vector<vector<int> >& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
            }
        }
    }

    int BFS(int x, int y, vector<vector<int> >& grid) {
        int count = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<int, int> > need_visit;
        bool visited[MAX][MAX] = {false, };

        need_visit.push(make_pair(x, y));
        visited[x][y] = true;

        count++;

        while(!need_visit.empty()) {
            int cx = need_visit.front().first;
            int cy = need_visit.front().second;

            need_visit.pop();


        }
    }
};

int main(void) {
    Solution solution;

    // vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(0);

    // vector<int> v2;
    // v2.push_back(0);
    // v2.push_back(1);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);

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