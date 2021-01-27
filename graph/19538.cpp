#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 200001

bool visited[MAX] = {false};

int N;
vector<int> graph[MAX];
int rumor[MAX];

void BFS(int value, int t) {
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(value, t));

    visited[value] = true;
    rumor[value] = 0;

    while(!need_visit.empty()) {
        int current = need_visit.front().first;
        int rumorTime = need_visit.front().second;
        
        need_visit.pop();

        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            
            // cout << "visited[" << i << "]: " << visited[i] << "\n\n";
             if(!visited[next] && next) {
                cout << "graph[" << current << "][" << i << "]: " << graph[current][i] << '\n';
                rumor[next] = rumorTime+1;
                need_visit.push(make_pair(next, rumorTime+1));
                visited[next] = true;
                break;
            }
        }
    }
}

int main(void) {
    memset(rumor, -1, sizeof(rumor));
    cin >> N;

    for(int i = 1; i <= N; i++) {
       while(1) {
           int value;
           cin >> value;

           if(value == 0) {
               break;
           }
           graph[i].push_back(value);
       }
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        int value;
        cin >> value;
        cout << "-------------" << value << "----------\n";
        BFS(value, 0);
         
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            cout << "graph[" << i << "][" << j << "] : "<<graph[i][j] << '\t';
        }
        cout << '\n';
    }

    for(int i = 1; i <= N; i++) {
        cout << rumor[i] << ' ';
    }
    
}