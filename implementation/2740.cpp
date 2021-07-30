#include <iostream>
#include <vector>

using namespace std;

#define MAX 101

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> A[MAX];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int value;
            cin >> value;
            A[i].push_back(value);
        }
    }

    int K;
    cin >> M >> K;

    vector<int> B[MAX];

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            int value;
            cin >> value;
            B[i].push_back(value);
        }
    }

    vector<int> answer[MAX];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            int result = 0;

           for(int k = 0; k < M; k++) {
               result += A[i][k]*B[k][j];
           }

           answer[i].push_back(result);

        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}