#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 10001

using namespace std;

bool visited[MAX];

int start_node, end_node;
int N, M;

vector<pair<int, int> > island[MAX];

bool BFS(int avgWeight){

    queue<int> need_visit;
    
    need_visit.push(start_node);
    visited[start_node] = true;

    while(!need_visit.empty()){
        int node = need_visit.front();

        need_visit.pop();

        for(int i = 0; i < island[node].size(); i++){
            int next = island[node][i].first;
            int weight = island[node][i].second;

            if(!visited[next] &&  weight >= avgWeight){
                visited[next] = true;
                need_visit.push(next);
            }
        }
    }
    return visited[end_node];
}

int main(void){
    int left = __INT_MAX__;
    int right = 0;
    int result;

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b, weight;
        cin >> a >> b >> weight;

        island[a].push_back(make_pair(b, weight));
        island[b].push_back(make_pair(a, weight));

        left = min(left, weight);
        right = max(right, weight);
    }

    cin >> start_node >> end_node;

    while(left <= right){
        int mid = (left + right) / 2;

        if(BFS(mid)){
            // 중량 늘리기
            left = mid + 1;
            result = mid;
        } else {
            // 중량 줄이기
            right = mid - 1;
        }
        memset(visited, false, sizeof(visited));
    }

    cout << result << '\n';
}