#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define P pair<int, int>

bool cmp (P a, P b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    int N;
    cin >> N;

    vector<P> v;

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}