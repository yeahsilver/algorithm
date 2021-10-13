#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> matching[MAX];
int edges[MAX];
bool visited[MAX];


bool dfs(int x) {
    for(int i = 0; i < matching[x].size(); i++){
        int next = matching[x][i];

        if(visited[next]) continue;

        visited[next] = true;

        if(edges[next] == 0 || dfs(edges[next])){
            edges[next] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    int test_case;
    cin >> test_case;

    while(test_case--){
        int N, M;
        cin >> N >> M;

        for(int i = 1; i <= M; i++){
            int start, end;
            cin >> start >> end;
            
            for(int j = start; j <= end; j++){
                matching[i].push_back(j);
            }   
        }

        int cnt = 0;
        
        for(int i = 1 ; i <= N; i++) {
            fill(visited, visited + MAX, false);
            if(dfs(i)) cnt++;
        }
        cout << cnt << '\n';
    }
}