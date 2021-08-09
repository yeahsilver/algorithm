#include <iostream>
#include <vector>

using namespace std;

#define MAX 101

int main(void) {
    int N;
    cin >> N;

    vector<pair<int, int> > v;

    v.push_back(make_pair(0, 0));

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    int dp[MAX] = {};

    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i].second > v[j].second && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
            }
        }
    }

    int maxValue = 0;

    for(int i = 0; i <= N; i++) {
        if(maxValue < dp[i]) {
            maxValue = dp[i];
        }
    }

    cout << N-maxValue << '\n';
}