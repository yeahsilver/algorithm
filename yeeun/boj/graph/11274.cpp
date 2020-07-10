// 미완성
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>* graph, bool* visited, int start_node){
	// 1. 첫 노드를 queue에 삽입
	queue<int> need_visit;
	need_visit.push(start_node);
	
	// 2. 첫 노드를 저장하고, pop
	int node = need_visit.front();
	cout << "first node:" << node << '\n';
	need_visit.pop();
	
	// 3. queue가 empty일 때 까지 반복문 돌리기
	while(!need_visit.empty()){
		for(int i = 0; i < graph[node].size(); i++){
		// 4. 다음 node를 저장하고, visited 여부 따지기
			int next = graph[node][i];
			
			if(!visited[next]){
				// 5. 만약 visited 하지 않았으면,need_visit에 노드를 추가한 뒤, visited = true 체크
				cout <<"next node: " <<next << '\n';
				need_visit.push(next);
				visited[next] = true;	
			}
			cout << "next!" << '\n';
		} 
	}
}


int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// 변수 생성
	int edges, vertices;
	int cnt = 0;
	bool visited[edges + 1];

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
	
	for(int i = 1; i <= edges; i++){
		BFS(graph, visited, i);
	}
}
