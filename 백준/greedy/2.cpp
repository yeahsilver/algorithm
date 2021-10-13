#include <iostream>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    int cnt = 0;
    while(1) {
        // 탈출 조건: N이 1일 때
        if(N == 1) break;

        if(N%K == 0) {
            N/=K;
        } else {
            N-=1;
        }

        cnt++;
    }

    cout << cnt << '\n';
}