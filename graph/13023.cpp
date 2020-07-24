#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 2000

bool visited[MAX] = {false, };

vector<int> relation[MAX];


void DFS(int idx, int depth){
    visited[idx] = true;

    if(depth == 4){
        cout << 1 << '\n';
        exit(0);
    }

    for(int i = 0; i < relation[idx].size(); i++){
        if(!visited[relation[idx][i]]){
            DFS(relation[idx][i], depth + 1);
        }
    }

    visited[idx] = false;
}

int main(void){
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        DFS(i, 0);
    }

    cout << 0 <<'\n';
}