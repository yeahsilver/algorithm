#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 1001
int N, M, V;

int graph[MAX][MAX];
int visited[MAX];

void DFS(int node){
    visited[node] = 1;
    cout << node << ' ';

    for(int i = 1; i <= N; i++){
        if(graph[node][i] && !visited[i]){
            visited[i] = 1;
            DFS(i);
        }
    }

}

void BFS(int node){
    queue<int> need_visit;
    need_visit.push(node);
    visited[node] = 1;

    while(!need_visit.empty()){
        int front = need_visit.front();
        need_visit.pop();
        cout << front << ' ';

        for(int i = 1; i <= N; i++){
            if(graph[front][i] && !visited[i]){
                visited[i] = 1;
                need_visit.push(i);
            }
        }
    }
}

void connectGraph(){
    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1;
    }
}

int main(void){

    cin >> N >> M >> V;

    connectGraph();

    DFS(V);
    cout << '\n';
    memset(visited,0, sizeof(visited));

    BFS(V);
}