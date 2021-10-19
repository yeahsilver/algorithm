#include <iostream>

#define MAX 15

using namespace std;

int n;
int answer = 0;
int column[MAX];

bool promising(int x) {
    for(int i = 0; i < x; i++) {
        if(column[x] == column[i] || abs(column[x] - column[i]) == x-i) {
            return false;
        }
    }
    return true;
}

void nqueens(int depth) {
    if(n == depth) {
        answer++;
    } else {
        for(int i = 0; i < n; i++) {
            column[depth] = i;
            if(promising(depth)) {
                nqueens(depth+1);
            }
        }
    }
}

int main(void) {
    cin >> n;

    nqueens(0);
    cout << answer << '\n';
}
