#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;

int visited[MAX] = {0,};

int BFS(int node, int depth){
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(node, depth));
    visited[node] = 1;

    while(!need_visit.empty()){
        int first = need_visit.front().first;
        int second = need_visit.front().second;

        need_visit.pop();

        if(first == K){
            return second;
        }

        if(first-1 >= 0 && !visited[first-1]){
            need_visit.push(make_pair(first-1, second+1));
            visited[first-1] = 1;
        }

        if(first+1 < MAX && !visited[first+1]){
            need_visit.push(make_pair(first+1, second+1));
            visited[first+1] = 1;
        }

        if(first*2 < MAX && !visited[first*2]){
            need_visit.push(make_pair(first *2, second+1));
            visited[first*2] = 1;
        }
    }
    return 0;
}

int main(void){
    cin >> N >> K;
    cout << BFS(N,0) << '\n';
}