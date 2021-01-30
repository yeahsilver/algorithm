#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100001

bool visited[MAX];

int N;
int sum = 0;
int endValue = 0;

vector<pair<int, int> > graph[MAX];

void DFS(int value, int weight) {
    if(visited[value]) {
        return;
    }

    visited[value] = true;

    if(sum < weight) {
        sum = weight;
        endValue = value;
    }

    for(int i = 0; i < graph[value].size(); i++) {
        DFS(graph[value][i].first, weight + graph[value][i].second);
    }

}

int main(void) {
    memset(visited, false, sizeof(visited));

    cin >> N;

    for(int i = 0; i < N-1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;

        graph[parent].push_back(make_pair(child, weight));
        graph[child].push_back(make_pair(parent, weight));
    }

    DFS(1, 0);

    sum = 0;
    memset(visited, false, sizeof(visited));

    DFS(endValue, 0);

    cout << sum << '\n';
}