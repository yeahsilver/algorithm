#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<pair<int, int> > v(N+1);


    for(int i = 1; i <= N; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i <= N; i++){
        int deadline = v[i].first;
        pq.push(v[i].second);

        while(deadline < pq.size()){ 
            // deadline < pq.size()하는 이유
            // deadline보다 pq.size()가 크면 풀 수 없는 문제가 있다는 것이기 때문

            pq.pop();
        }
    }

    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';
}