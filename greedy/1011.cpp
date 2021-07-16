#include <iostream>

using namespace std;

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        int src, dst;
        cin >> src >> dst;

        int cnt = 1;

        while(1) {
            // 탈출 조건: src 와 dst가 동일할 때
            if(src == dst) break;

            src+1 == dst ? src+=1 : src+=2;
            cnt++;
        }

        cout << cnt;
    }
}