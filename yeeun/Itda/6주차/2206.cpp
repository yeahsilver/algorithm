#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;

int mX[4] = {0,0,-1,1}; 
int mY[4] = {-1,1,0,0};

int graph[MAX][MAX] = {};
int visited[MAX][MAX] = {};

int BFS(){
    queue<>
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> graph[i];
        cout << BFS();
    }
}