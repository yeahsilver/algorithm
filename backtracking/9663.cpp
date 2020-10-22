#include <iostream>

#define MAX 15

using namespace std;

int col[MAX];
int N, unattackable = 0;

bool promising(int row){
    for(int i = 0; i < row; i++){ // row만큼
        if(col[i] == col[row] || abs(col[row]- col[i]) == row-i){
            // col[i] == col[row] ==> 같은 column 선상에 있다
            // abs(col[row] - col[i]) == row - i
            // ==> (col[row], row), (col[i],i)일 때
            // col[row]-col[i] = row -i 이면 같은 대각선 상에 존재 한다는 의미임
            return false;
        }
    }
    return true;
}

void n_queens(int location){
    if(location == N){
        unattackable++;
    } else {
        for(int i = 0; i < N; i++){
            col[location] = i; // 같은 행, 대각선, 아래 위로 말이 있는지 확인하기 위함
            if(promising(location)){ // 같은 행, 대각선, 아래 위로 말이 없으면
                n_queens(location+1); // 다음 줄로 넘어가서 체크하기!
            }
        }
    }
}

int main(void){
    cin >> N;
    n_queens(0);
    cout << unattackable << '\n';
}