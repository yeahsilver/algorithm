#include <iostream>
#include <vector>

using namespace std;

bool isVisited[1001] = {false, };

int n;
int total = 0;

int romeValues[4] = {1, 5, 10, 50};

void createRomeNum(int count, int sum, int iterate) {
    // 탈출 조건 n이 n과 같을 때
    if(count == n) {
        if(!isVisited[sum]) {
            isVisited[sum] = true;
            total++;
        }

        return;
    }

    for(int i = iterate; i < 4; i++) {
        createRomeNum(count+1, sum+romeValues[i], i);
    }
}


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    createRomeNum(0, 0, 0);

    cout << total << '\n';
}