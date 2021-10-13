#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 4001
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<int> A, B, C, D;

    for(int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    vector<int> sumAB;
    vector<int> sumCD;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sumAB.push_back(A[i] + B[j]);
            sumCD.push_back(C[i] + D[j]);
        }
    }

    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());

    long long answer = 0;

    for(int i = 0; i < sumAB.size(); i++) {
        long long value = -sumAB[i];

        auto upper = upper_bound(sumCD.begin(), sumCD.end(), value);
        auto lower = lower_bound(sumCD.begin(), sumCD.end(), value);
        answer += (upper-lower);
    }

    cout << answer << '\n';
}