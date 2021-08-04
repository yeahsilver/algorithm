#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 10001

int id = 0, d[MAX]; // 각 노드마다 고유한 번호 할당
bool finished[MAX]; // 특정 노드에 대한 dfs가 끝났는지 확인
vector<int> graph[MAX]; // 인접 노드 저장
vector<vector<int> > SCC;
stack<int> s;

// DFS는 총 정점의 개수만큼 실행
int dfs(int x) {
    d[x] = ++id; // 맨처음 부모로 설정된 값: d[x] / 노드마다 고유한 번호 할당
    s.push(x); // 스택에 자기 자신을 십입

    int parent = d[x];

    for(int i = 0; i <graph[x].size(); i++) {
        int y = graph[x][i]; // 인접한 노드를 가리킴

        if(d[y] == 0) { // 해당 노드를 방문한 적이 없다면
            // 해당 노드로 dfs 설정 (더 작은 값으로 부모 값이 갱신되게 만들기)
            parent = min(parent, dfs(y));

        } else if(!finished[y]) { // 처리 중인 이웃
            parent = min(parent, d[y]);
        }

        if(parent == d[x]) {
            vector<int> scc;

            while(1) {
                int t = s.top();
                s.pop();
                scc.push_back(t);
                finished[t] = true;
                
                // 부모 값이 나온 경우 멈추기
                if(t == x) {
                    break;
                }
            }

            SCC.push_back(scc);
        }
    }

    // 자신의 부모값 반환
    return parent;
}

int main(void) {
    int V, E;
    cin >> V >> E;


    for(int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);
    }

    for(int i = 1; i <= V; i++) {
        if(d[i] == 0) {
            dfs(i);
        }
    }

    cout << SCC.size()<< '\n';
    for(int i = 0; i < SCC.size(); i++) {
        for(int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << ' ';
        }
        cout << "-1\n";
    }
}