#include <iostream>
using namespace std;

#define MAX 1001

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int map[MAX][MAX];

    cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << map[i][j] << '\t';
        }
        cout << '\n';
    }
}