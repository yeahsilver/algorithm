//메모리 초과
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    unsigned N, k;
    cin >> N >> k;
    priority_queue<unsigned, vector<unsigned>, greater<unsigned> > pq;
    for(int i = 1; i <=N; i++){
        for(int j = 1; j<=N; j++){
            pq.push(i*j);
        }
    }
    for(int i = 0; i <k; i++){
        pq.pop();
    }
    cout<<pq.top();
}

