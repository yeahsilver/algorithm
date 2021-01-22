#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define P pair<int, int>

int main(void) {
    int num;
    cin >> num;

    vector<P> info(num+1);

    for(int i = 1; i <= num; i++) {
        cin >> info[i].first >> info[i].second;
    } 

    sort(info.begin(), info.end());

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i <= num; i++) {
        int deadline = info[i].first;
        pq.push(info[i].second);

        while(pq.size() > deadline){
            pq.pop();
        }
    }

    int total = 0;

    while(!pq.empty()) {
        total+=pq.top();
        pq.pop();
    }

    cout << total << '\n';
}