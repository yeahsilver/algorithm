#include <iostream>

#define NUM 4
#define INF 10000000

using namespace std;

// 자료 배열 초기화
int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

int main(void) {
    int d[NUM][NUM];

    for(int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++) {
            d[i][j] = a[i][j];
        }
    }
    
    // K = 거쳐가는 노드
    for(int k = 0; k < NUM; k++) {
        // i = 출발 노드
        for(int i = 0; i < NUM; i++) {
            // j = 도착 노드
            for(int j = 0; j < NUM; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for(int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++) {
            cout << d[i][j] << '\t';
        }
        cout << '\n';
    }
}
