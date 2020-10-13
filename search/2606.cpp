#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt = 0;

void BFS(vector<int>* graph, int start, bool* visited){
	queue<int> need_visit;
	need_visit.push(start);
	visited[start] = true;
	
	while(!need_visit.empty()){
		int front = need_visit.front();
		need_visit.pop();
		
		for(int i = 0; i < graph[front].size(); i++){
			int next = graph[front][i];
			if(!visited[next]){
				need_visit.push(next);
				visited[next] = true;
				cnt++;
			}
		}
	}
}

int main(void){
	int vertex, edge;
	cin >> vertex >> edge;
	
	vector<int> graph[vertex+1];
	bool visited[vertex+1];
	
	fill(visited, visited+vertex+1, false);
	
	for(int i = 0; i < edge; i++){
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	BFS(graph, 1, visited);
	
	cout << cnt << '\n';
}
