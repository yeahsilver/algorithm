#include <iostream>

#define MAX 15

using namespace std;

int col[MAX];
int N, result = 0;

bool promising(int location){
    for(int i = 0; i < location; i++){
        if(col[i] == col[location] || abs(col[location]- col[i]) == location-i){
            return false;
        }
    }
    return true;
}

void n_queens(int location){
    if(location == N){
        result++;
    } else {
        for(int i = 0; i < N; i++){
            col[location] = i;
            if(promising(location)){
                n_queens(location+1);
            }
        }
    }
}

int main(void){
    cin >> N;
    n_queens(0);
    cout << result << '\n';
}