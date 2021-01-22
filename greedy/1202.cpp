#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K; 

    int* bag = new int[K];
    vector<pair<int, int> > jewel;

    for(int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        jewel.push_back(make_pair(weight, value));
    }

    sort(jewel.begin(), jewel.end());

    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    sort(bag, bag+K);

    priority_queue<int> pq;
    long long total = 0;
    int j = 0;

    for(int i = 0; i < K; i++){
        while(j < N && bag[j] >= jewel[i].first){
            pq.push(jewel[j++].second); 
        }
        if(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';

