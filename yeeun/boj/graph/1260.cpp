#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;
int N, M, V;
int adjacent[MAX][MAX];
int visited[MAX];
queue<int> q;


void dfs(int input)
{
    visited[input] = 1;
    cout << input << " ";
 
    for(int i=1; i<=N; i++)
        if (adjacent[input][i] && !visited[i]){
            visited[i] = 1;
            dfs(i);
    }
}

void bfs(int input){
    q.push(input);
    visited[input] = 1;

    while(!q.empty()){
        input = q.front();
        q.pop();
        cout<<input<<" ";
        for(int i = 1; i <= N; i++){
            if(adjacent[input][i] && !visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }

    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N>>M>>V;
    for(int i = 1; i <= M; i++){
        int from, to;
        cin>>from>>to;
        adjacent[to][from] = 1;
        adjacent[from][to] = 1;
    }

    dfs(V);
    cout<<'\n';
    memset(visited, false,sizeof(visited));
    bfs(V);
    cout<<'\n';
}

