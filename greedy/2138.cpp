#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define INF 100001

void changeLight(string &before, int index) {
    for(int i = index-1; i <= index+1; i++) {
        // 첫번째이거나 마지막이면 건너뛰어야함
        if(i < 0 || i > before.size()) {
            continue;
        }

        if(before[i] == '0') {
            before[i] = '1';
        } else {
            before[i] = '0';
        }
    }
}

int countCaseNumber(string before, string after, bool isEqual) {
    int cnt = 0;

    if(isEqual) {
        changeLight(before, 0);
        cnt++;
    }

    for(int i = 1; i < before.size(); i++) {
        if(before[i-1] != after[i-1]) {
            changeLight(before, i);
            cnt++;
        }
    }

    if(before != after) {
        cnt = INF;
    }

    return cnt;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    string before;
    string after;

    cin >> before >> after;

    int answer = min(countCaseNumber(before, after, 0), countCaseNumber(before, after, 1));
    answer == INF ? cout << "-1\n"  : cout << answer << '\n';
}