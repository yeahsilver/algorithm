#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 51

struct Count {
    int whiteBlackCount;
    int blackWhiteCount;
};

int countMinimum(int M, int N, vector<bool>* v) {
    int minValue = __INT_MAX__;

    // 1. 세로로
    int start = 0;
    int end = 7;

    cout << "세로\n";

    while(end < M) {
        int count = 0;

        for(int i = start; i < end; i++) {
            for(int j = 0; j < 8; j++) {
                if(v[i][j] == false) {
                    count++;
                }
            }
        }

        cout << start << '\t' << end << '\t' << count << '\n';

        if(minValue > count) {
            minValue = count;
        }

        start++;
        end++;
    }

    start = 0;
    end = 7;

    // 2. 가로로
    cout << "가로\n";
    while(end < N) {
        int count = 0;

        for(int i = 0; i < 8; i++) {
            for(int j = start; j < end; j++) {
                if(v[i][j] == false) {
                    count++;
                }
            }
        }

        cout << start << '\t' << end << '\t' << count << '\n';

        if(minValue > count) {
            minValue = count;
        }
        
        start++;
        end++;
    }

    return minValue;
}

Count countChess(int M, int N, vector<string> chess, vector<bool>* whiteBlack, vector<bool>* blackWhite) {
    Count count;
    count.blackWhiteCount = 0;
    count.whiteBlackCount = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(i%2==0) {
                if((j%2==0 && chess[i][j]=='W') || (j%2 == 1 && chess[i][j] == 'B')) {
                    whiteBlack[i].push_back(true);

                    blackWhite[i].push_back(false);
                    count.blackWhiteCount++;

                } else {
                    blackWhite[i].push_back(true);

                    whiteBlack[i].push_back(false);
                    count.whiteBlackCount++;
                    
                }
            } else {
                if((j%2==1 && chess[i][j]=='W') || (j%2 == 0 && chess[i][j] == 'B')){
                    whiteBlack[i].push_back(true);

                    blackWhite[i].push_back(false);
                    count.blackWhiteCount++;

                } else {
                     blackWhite[i].push_back(true);
                    
                    whiteBlack[i].push_back(false);
                    count.whiteBlackCount++;
                }
            }
        }
    }

    return count;
}

int main(void) {
    int M, N;
    cin >> M >> N;

    vector<string> chess;

    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        chess.push_back(s);
    }

    vector<bool> whiteBlack[MAX];
    vector<bool> blackWhite[MAX];

    Count count = countChess(M, N, chess, whiteBlack, blackWhite);
    
    bool isBlackFirst = false;

    if(count.blackWhiteCount < count.whiteBlackCount) {
        isBlackFirst = true;
    } else {
        isBlackFirst = false;
    }

    if(M == 8 && N == 8) {
        if(isBlackFirst) {
            cout << count.blackWhiteCount << '\n';
        } else {
            cout << count.whiteBlackCount << '\n';
        }

        return 0;
    }
    
    int minValue = min(countMinimum(M, N, blackWhite), countMinimum(M, N, whiteBlack));
    
    cout << minValue << '\n';
}