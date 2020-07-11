// 미완성
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>* graph, bool visited[], int start_node){
	// 1. 첫 노드를 queue에 삽입
	queue<int> need_visit;
	need_visit.push(start_node);
	visited[start_node] = true;
	
	// 2. queue가 empty일 때 까지 반복문 돌리기
	while(!need_visit.empty()){
		// 3. 첫 노드를 저장하고, pop
		int node = need_visit.front();
		need_visit.pop();
		
		for(int i = 0; i < graph[node].size(); i++){
		// 4. 다음 node를 저장하고, visited 여부 따지기
			int next = graph[node][i];
			
			if(!visited[next]){
				// 5. 만약 visited 하지 않았으면,need_visit에 노드를 추가한 뒤, visited = true 체크
				need_visit.push(next);
				visited[next] = true;	
			}
		} 
	}
}

int connect(int n, vector<int>* graph){
	bool visited[n + 1];
	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
		if(visited[i]) continue;
		
		BFS(graph, visited, i);
		cnt++;
	}
	
	return cnt;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// 변수 생성
	int edges, vertices;
	

	// 1. edges, vertices 받기
	
	cin >> edges >> vertices;
	
	// 2. edges 개수만큼 배열 생성
	vector<int> graph[edges+1];
	
	// 3. 연결되어있는 정점 연결
	for(int i = 0; i < vertices; i++){
		int start, end;
		
		cin>> start >> end;
		
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	cout << connect(edges, graph) << '\n';
}
