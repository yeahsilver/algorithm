#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 51
vector<bool> whiteBlack[MAX];
vector<bool> blackWhite[MAX];

int countWB(int x, int y, vector<string> chess) {
    int count = 0;

    for(int i = x; i < x+8; i++) {
        for(int j = y; j < y+8; j++) {
            if(whiteBlack[i][j] == false) {
                count++;
            }
        }
    }

    return count;
}

int countBW(int x, int y, vector<string> chess) {
    int count = 0;

    for(int i = x; i < x+8; i++) {
        for(int j = y; j < y+8; j++) {
            if(blackWhite[i][j] == false) {
                count++;
            }
        }
    }

    return count;
}

void countChess(int N, int M, vector<string> chess) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i%2==0) {
                if((j%2==0 && chess[i][j]=='W') || (j%2 == 1 && chess[i][j] == 'B')) {
                    whiteBlack[i].push_back(true);

                    blackWhite[i].push_back(false);
                } else {
                    blackWhite[i].push_back(true);

                    whiteBlack[i].push_back(false);
                }
            } else {
                if((j%2==1 && chess[i][j]=='W') || (j%2 == 0 && chess[i][j] == 'B')){
                    whiteBlack[i].push_back(true);

                    blackWhite[i].push_back(false);

                } else {
                     blackWhite[i].push_back(true);
                    
                    whiteBlack[i].push_back(false);
                }
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector<string> chess;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        chess.push_back(s);
    }   

    countChess(N, M, chess);

    int minValue = __INT_MAX__;

    for(int i = 0; i+7 < N; i++) {
        for(int j = 0; j+7 < M; j++) {
            minValue = min(minValue, min(countBW(i ,j, chess), countWB(i, j, chess)));
        }
    }

    cout << minValue << '\n';
}