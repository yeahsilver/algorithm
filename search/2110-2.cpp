#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int N, C;
    cin >> N >> C;

    vector<int> home;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        home.push_back(value);
    }

    sort(home.begin(), home.end());

    int start = 0;
    int end = home[N-1];
    int answer = 0;

    while(start <= end) {
        int middle = (start + end) / 2;
        int prev = home[0];
        int cnt = 1;

        for(int i = 1; i < N; i++) {
            if(home[i] - prev  >= middle) {
                prev = home[i];
                cnt++;
            }
        }

        if(cnt >= C) {
            start = middle + 1;
            answer = max(middle, answer);
        } else {
            end = middle -1;
        }
    }

    cout << answer << '\n';
    return 0;
}