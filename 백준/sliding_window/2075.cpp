#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 2250000
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            long long value;
            cin >> value;
            pq.push(value);

            if(pq.size() > N) {
                pq.pop();
            }
        }
    }
    
    cout << pq.top() << '\n';
    
}
