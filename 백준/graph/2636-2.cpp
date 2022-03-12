#include <iostream>
#include <priority_queue>
#include <vector>

#define MAX 101

using namespace std;

int main(void) {
  int N, M;
  vector<int> graph[MAX];
  
  cin >> N >> M;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int value;
      cin >> value;
      
      graph[i].push_back(value);
    }
  }
}
