#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cnt = 0;

void dfs(int start, bool* visited, vector<int>* graph){
    cnt++;
    if(visited[start]){
        return;
    }

    visited[start] = true;

    for(long unsigned int i = 0; i < graph[start].size(); i++){
        int next = graph[start][i];
        dfs(next, visited, graph);
    }
}

int main(void){
    int vertex, edge;
    cin >> vertex >> edge;

    vector<int> graph[vertex + 1];

    for(int i = 0; i < edge; i++){
        int from, to;
        cin >> from >> to;

        graph[to].push_back(from);
    }

    int MAX = 0;
    int check[vertex+1];

    for(int i = 1; i <= vertex; i++){
        bool visited[vertex];
        fill(visited, visited + vertex + 1, false);
        dfs(i, visited, graph);

        check[i] = cnt;

        if(cnt >= MAX){
            MAX = cnt;
        }

        cnt = 0;
    }

    for(int i = 1; i <= vertex; i++){
        if(check[i] == MAX){
            cout << i << ' ';
        }
    }
}