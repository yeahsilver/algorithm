#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;

        v.push_back(value);
    }

    int maxValue = 0;

    sort(v.begin(), v.end());
    
    do {
        vector<int> tmp;
        int sum = 0;

        for(int i = 0; i < v.size(); i++) {
            tmp.push_back(v[i]);
        }

        for(int i = 1; i < v.size(); i++) {
            sum += abs(v[i-1]-v[i]);
        }

        maxValue = max(sum, maxValue);

    } while(next_permutation(v.begin(), v.end()));

    cout << maxValue << '\n';
}