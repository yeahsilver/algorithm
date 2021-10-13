#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    vector<int> numbers(N);
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;

        numbers[i] = value;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < N; i++) {
        pq.push(make_pair(numbers[i], i));

        int idx = pq.top().second;
        
        while(idx < i-L+1) {
            pq.pop();
            idx = pq.top().second;
        }

        cout << pq.top().first <<  ' ';
    }   
}