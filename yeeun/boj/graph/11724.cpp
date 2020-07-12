#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>* graph, bool visited[], int start_node){
	/*
		BFS는 queue의 구조를 사용하여 작동하기에, need_visit라는 queue를 생성하여 방문해야하는 노드를 저장해준다. 
		- need_visit: 방문 예정인 노드
		- visited: 방문한 노드
		- start_node: 처음으로 받은 노드
	*/

	// 1. 첫 노드를 queue에 삽입
	queue<int> need_visit;
	visited[start_node] = true;
	need_visit.push(start_node);
	
	// 2. queue가 empty일 때 까지 반복문 돌리기
	while(!need_visit.empty()){
		// 3. 첫 노드를 저장하고, pop
		int node = need_visit.front();
		need_visit.pop();
		
		for(int i = 0; i < graph[node].size(); i++){
		// 4. 다음 node를 저장하고, visited 여부 따지기
			int next_node = graph[node][i];
			
			if(!visited[next_node]){
				// 5. 만약 visited 하지 않았으면,need_visit에 노드를 추가한 뒤, visited = true 체크
				need_visit.push(next_node);
				visited[next_node] = true;	
			}
		} 
	}
}

int find_connect_factor(int n, vector<int>* graph){
	// 1. 변수 할당
	int cnt = 0;
	bool visited[n + 1];
	
	// 2. 배열 초기화
	// 아직 노드를 방문하지 않았기에, 모든 원소를 false로 할당.
	for(int i = 0; i < n+1; i++){
		visited[i] = false;
	}
	
	/* 3. 연결 요소 찾기
		> if | 노드를 이미 방문했다면, 이미 간선으로 연결되어있는 것이기에, 다음 노드로 넘어감
		> else | 노드를 방문하지 않았다면, 간선으로 연결되어있지 않음을 나타내는 것이기에, BFS 함수를 사용하여 노드를 탐색한다. 
		  그리고 문제에서 원하는 출력값은 연결 요소의 개수이므로, BFS가 동작할 때 마다 cnt를 1씩 증가시킨다. 
	*/
	for(int i = 1; i <= n; i++){
		if(visited[i]) continue;
		
		BFS(graph, visited, i);
		cnt++;
	}
	
	// 4. 연결요소의 개수 반환
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
	// 방향성이 없는 그래프이기 때문에 start -> end, end -> start의 경우를 배열에 모두 저장해주어야함.
	for(int i = 0; i < vertices; i++){
		int start, end;
		
		cin>> start >> end;
		
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	// 4. 연결 요소의 개수 출력
	cout << find_connect_factor(edges, graph) << '\n';
}
