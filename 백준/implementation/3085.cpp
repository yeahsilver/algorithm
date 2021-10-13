#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 51

int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int maxCount = 0;

void swap(int cx, int cy, int nx, int ny, vector<char>* board) {
    char temp = board[cx][cy];
    board[cx][cy] = board[nx][ny];
    board[nx][ny] = temp;
}

void countRowCandies(vector<char>* board) {
    for(int i = 0; i < n; i++) {
        char value = board[i][0];
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(value == board[i][j]) {
                count++;
            } else {
                if(count > maxCount) {
                    maxCount = count;
                    
                }

                value = board[i][j];
                count = 1;
            }
        }
        if(count > maxCount) {
            maxCount = count;
        }
    }
}

void countColumnCandies(vector<char>* board) {
    for(int i = 0; i < n; i++) {
        char value = board[0][i];
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(value == board[j][i]) {
                count++;
            } else {
                if(count > maxCount) {
                    maxCount = count;  
                }

                value = board[j][i];
                count = 1;
            }
        }

        if(count > maxCount) {
            maxCount = count;
        }
    }
}

int main(void) {
    cin >> n;

    vector<char> board[MAX];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char value;
            cin >> value;
            board[i].push_back(value);
        }
    }

    for(int cx = 0; cx < n; cx++) {
        for(int cy = 0; cy < n; cy++) {
            
            for(int k = 0; k < 4; k++) {
                int nx = cx+dx[k];
                int ny = cy+dy[k];
                
                if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) {
                    continue;
                }

                swap(cx, cy, nx, ny, board);

                int rowCount = 0;
                int columnCount = 0;
                
                countRowCandies(board);
                countColumnCandies(board);

                swap(cx, cy, nx, ny, board);
            }
        }
    }

    cout << maxCount << '\n';
}