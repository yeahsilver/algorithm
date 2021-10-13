#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;

#define P pair<int, int>

bool cmp(P a, P b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    int num;
    cin >> num;
    
    vector<P> graph;
    
    for(int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;

        graph.push_back(make_pair(x, y));
    }

    sort(graph.begin(), graph.end(), cmp);

    for(int i = 0; i < num; i++) {
        cout << graph[i].first << ' ' << graph[i].second << '\n';
    }
}

