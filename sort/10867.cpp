#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v;

    for(int i= 0 ; i < N; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}