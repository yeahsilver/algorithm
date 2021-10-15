#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    long long T;
    cin >> T;

    int a;
    cin >> a;

    vector<long long> v1(a);

    for(int i = 0; i < a; i++) {
        cin >> v1[i];
    }

    int b;
    cin >> b;

    vector<long long> v2(b);

    for(int i = 0; i < b; i++) {
        cin >> v2[i];
    }

    vector<long long> sumA;

    for(int i = 0; i < a; i++) {
        long long value = v1[i];
        sumA.push_back(value);
        for(int j = i+1; j < a; j++) {
            value += v1[j];
            sumA.push_back(value);
        }
    }

    vector<long long> sumB;

    for(int i = 0; i < b; i++) {
        long long value = v2[i];
        sumB.push_back(value);
        for(int j = i+1; j < b; j++) {
            value += v2[j];
            sumB.push_back(value);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    long long answer = 0;

    for(int i = 0; i < sumA.size(); i++) {
        long long value = T - sumA[i];
        
        int upper = upper_bound(sumB.begin(), sumB.end(), value) - sumB.end();
        int lower = lower_bound(sumB.begin(), sumB.end(), value) - sumB.end();

        answer += (upper-lower);
    }

    cout << answer << '\n';
}