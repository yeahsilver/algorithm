#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101
#define INF 10000
using namespace std;

int N, M;
int connections[MAX][MAX];

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int first, second;
        cin >> first >> second;
        connections[first][second] = 1;
        connections[second][first] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) continue;

                if(connections[i][k] && connections[k][j]) {
                    if(connections[i][j] == 0) {
                        connections[i][j] = connections[i][k] + connections[k][j];
                    } else {
                        connections[i][j] = min(connections[i][j], connections[i][k] + connections[k][j]);
                    }
                }
            }
        }
    }

    int maxValue = __INT_MAX__;
    int num;

    for(int i = 1; i <= N; i++) {
        int sum = 0;

        for(int j = 1; j <= N; j++) {
            sum += connections[i][j];
        }

        if(maxValue > sum) {
            num = i;
            maxValue = sum;
        }
    }

    cout << num << '\n';
}