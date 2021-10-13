#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

int edge, vertex, start; 
int graph[MAX][MAX];
int visited[MAX];

void DFS(int start) {
    visited[start] = 1;
    cout << start << ' ';

    for(int i = 1; i <= edge; i++) {
        int next = graph[start][i];

        if(!visited[i] && next) {
            visited[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int start) {
    queue<int> need_visit;

    need_visit.push(start);
    visited[start] = 1;

    while(!need_visit.empty()) {
        int now = need_visit.front();
        cout << now << ' ';

        need_visit.pop();

        for(int i = 1; i <= edge; i++) {
            int next = graph[now][i];
            if(!visited[i] && next ) {
                need_visit.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(void) {
    cin >> edge >> vertex >> start;

    for(int i = 0; i < vertex; i++) {
        int start, end;
        cin >> start >> end;

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    DFS(start);
    cout << '\n';
    memset(visited, false, sizeof(visited));
    BFS(start);
    
}