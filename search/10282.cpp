#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100001
#define INF 1e9

int main(void){
    int test_case;
    cin >> test_case;

    while(test_case--){
        int n, d, c;
        cin >> n >> d >> c;

        int dist[MAX];
        vector<pair<int, int> > computer[MAX];

        fill(dist, dist+n+1, INF);

        for(int i = 0; i < d; i++){
            int from, to, value;
            cin >> from >> to >> value;
            computer[to].push_back(make_pair(from, value));
        }

        priority_queue<pair<int, int> > need_visit;
        need_visit.push(make_pair(c, dist[c] = 0));

        while(!need_visit.empty()){
            int now = need_visit.top().first;
            int distance = need_visit.top().second;

            need_visit.pop();

            for(int i = 0; i < computer[now].size(); i++){
                int next = computer[now][i].first;
                int cost = computer[now][i].second;
                if(dist[next] > dist[now] + cost){
                    dist[next] = dist[now] + cost;
                    need_visit.push(make_pair(next, dist[next]));
                }
            }
        }
        int cnt = 0;
        int value = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i]!=INF){
                cnt++;
                value = max(dist[i], value);
            }
        }
        cout << cnt << ' ' << value << '\n';
    }
}