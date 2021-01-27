#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 101

bool visited[MAX];
vector<int> graph[MAX];

void BFS(int value) {
    queue<int> need_visit;
    need_visit.push(value);
    visited[value] = true;

    while(!need_visit.empty()) {
        int current = need_visit.front();
        need_visit.pop();

        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];

            if(!visited[next]) {
                need_visit.push(next);
                visited[next] = true;
            } 
        }
    }

}
 
int main(void) {
    memset(visited, false, sizeof(visited));

    int computer, edges;
    cin >> computer >> edges;

    for(int i = 0; i < edges; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    BFS(1);

    int result = 0;
    for(int i = 2; i <= computer; i++) {
        result+= visited[i];
    }

    cout << result << '\n';
}