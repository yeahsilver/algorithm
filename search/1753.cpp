#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20001
#define P pair<int, int>
#define INF 1e9

int V, E;
vector<P> graph[MAX];

vector<int> dijkstra(int start){
    vector<int> dist(V+1, INF);
    priority_queue<P> need_visit;
    need_visit.push(make_pair(start, dist[start]=0));

    while(!need_visit.empty()){
        int now = need_visit.top().first;
        int distance = need_visit.top().second;

        need_visit.pop();

        if(dist[now] < distance){
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int cost = graph[now][i].second + distance;

            if(dist[next] > cost){
                dist[next] = cost;
                need_visit.push(make_pair(next, cost));
            }
        }
    }
    return dist;
}

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;

    int startVertex;
    cin >> startVertex;

    for(int i = 0; i < E; i++){
        int from, to, value;
        cin >> from >> to >> value;
        graph[from].push_back(make_pair(to, value));
    }

    vector<int> result = dijkstra(startVertex);

    for(int i = 1; i <= V; i++){
        if(result[i] == INF){
            cout << "INF\n";
        } else {
            cout << result[i] << '\n';
        }
    }
}