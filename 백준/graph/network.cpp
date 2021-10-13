#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 201

bool visited[MAX] = {false, };

void bfs(int n, vector<vector<int> > computers, int start) {
    queue<int> need_visit;
    need_visit.push(start);
    
    visited[start] = true;
    
    while(!need_visit.empty()) {
        int now = need_visit.front();
        
        need_visit.pop();
        
        for(int i = 0; i < n; i++) {
            int next = computers[now][i];
            
            if(!visited[i] && next) {
                need_visit.push(next);
                visited[next] = true;
            }
        }
    }
}

int connect(int n, vector<vector<int> > computers) {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(!visited[i]) {
            bfs(n, computers, i);
            count++;
        }
    }
    
    return count;
}

int main(void) {
    int n = 3;
    vector<vector<int> > computers;
    
    computers[0].push_back(1);
    computers[0].push_back(1);
    computers[0].push_back(0);

    computers[1].push_back(1);
    computers[1].push_back(1);
    computers[1].push_back(0);

    computers[2].push_back(0);
    computers[2].push_back(0);
    computers[2].push_back(1);

    int answer = 0;
    return answer = connect(n, computers);

}
