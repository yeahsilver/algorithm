#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 32001

int N, M;
int inDegree[MAX] = {0, };

vector<int> problem[MAX];
priority_queue<int, vector<int>, greater<int> > pq;

void topologySort(){
    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int front = pq.top();
        pq.pop();

        cout << front << ' ';

        for(int i = 0; i < problem[front].size(); i++){
            int next = problem[front][i];
            if(--inDegree[next] == 0){
                pq.push(next);
            }
        }
    }
}

int main(void){
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int first, second;
        cin >> first >> second;
        problem[first].push_back(second);
        inDegree[second]++;
    }

    topologySort();
}