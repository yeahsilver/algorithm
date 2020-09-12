#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 500
#define P pair<int, int>
#define INF 1e9

int N, M;

vector<P> trace[MAX];

vector<int> dijkstra(int start, vector<P>* graph){
    vector<int> dist(N,INF);
    priority_queue<P> need_visit;
    need_visit.push(make_pair(start, dist[start]=0));

    while(!need_visit.empty()){
        int now = need_visit.top().first;
        int distance = need_visit.top().second;

        need_visit.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int cost = graph[now][i].second + distance;

            if(graph[now][i].second == -1){
                continue;
            }

            if(dist[next] > cost){
                dist[next] = cost;
                need_visit.push(make_pair(next, dist[next]));

                trace[next].clear();
                trace[next].push_back(make_pair(now, cost));

            } else if(dist[next] == cost){
                trace[next].push_back(make_pair(now, cost));
            }
        }
    }
    return dist;
}

void BFS(int end, vector<P>* graph){
    bool visited[MAX][MAX];

    queue<int> need_visit;
    need_visit.push(end);

    while(!need_visit.empty()){
        int now = need_visit.front();
        need_visit.pop();

        for(int i = 0; i < trace[now].size(); i++){
            int next = trace[now][i].first;

            if(visited[now][next]){
                continue;
            }

            for(int i = 0; i < graph[next].size(); i++){
                if(graph[next][i].first == now){
                    graph[next][i].second = -1;
                }
            }
            need_visit.push(next);
        }
    }
}

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> N >> M;

        if(N==0 && M==0){
            break;
        }

        int start, end;
        cin >> start >> end;

        vector<P> graph[MAX];
        for(int i = 0; i < M; i++){
            int from, to, value;
            cin >> from >> to >> value;
            graph[from].push_back(make_pair(to, value));
        }

        dijkstra(start, graph);

        BFS(end, graph);

        vector<int> result = dijkstra(start, graph);

        if(result[end] == INF){
            cout << -1 << '\n';
        } else {
            cout << result[end] << '\n';
        }
    }
}