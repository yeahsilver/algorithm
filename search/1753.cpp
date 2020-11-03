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
    priority_queue<P, vector<P>,  greater<P> > need_visit;
    need_visit.push(make_pair(dist[start]=0, start));

    while(!need_visit.empty()){
        int distance = need_visit.top().first;
        int now = need_visit.top().second;
        need_visit.pop();

        if(dist[now] < distance){
            continue;
        }

        for(int i = 0; i < graph[now].size(); i++){
            int cost = graph[now][i].first + distance;
            int next = graph[now][i].second;

            if(dist[next] > cost){
                need_visit.push(make_pair(dist[next] = cost, next));
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
        graph[from].push_back(make_pair(value, to));
    }

    vector<int> result = dijkstra(startVertex);

    for(int i = 1; i <= V; i++){
        if(result[i] == INF){
            cout << "INF" <<'\n';
        } else {
            cout << result[i] << '\n';
        }
    }
}