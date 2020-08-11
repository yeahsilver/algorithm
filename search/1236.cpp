#include <iostream>

using namespace std;

int main(void){
    int N, M;
    int rowCnt = 0;
    int columnCnt = 0;
    char castle[50][50];

    cin >> N >> M;

    int row[50] = {0,};
    int column[50] = {0,};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> castle[i][j];

            if(castle[i][j] == 'X'){
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(row[i] == 0){
            rowCnt++;
        }
    }

    for(int j = 0; j < M; j++){
        if(column[j] == 0){
            columnCnt++;
        }
    }

    cout << max(rowCnt, columnCnt) << '\n';
}