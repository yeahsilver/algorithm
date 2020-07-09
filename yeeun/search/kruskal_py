graph = {
    'vertices': ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
    'edges': [
        (7, 'A', 'B'),
        (5, 'A', 'D'),
        (7, 'B', 'A'),
        (8, 'B', 'C'),
        (9, 'B', 'D'),
        (7, 'B', 'E'),
        (8, 'C', 'B'),
        (5, 'C', 'E'),
        (5, 'D', 'A'),
        (9, 'D', 'B'),
        (7, 'D', 'E'),
        (6, 'D', 'F'),
        (7, 'E', 'B'),
        (5, 'E', 'C'),
        (7, 'E', 'D'),
        (8, 'E', 'F'),
        (9, 'E', 'G'),
        (6, 'F', 'D'),
        (8, 'F', 'E'),
        (11, 'F', 'G'),
        (9, 'G', 'E'),
        (11, 'G', 'F')
    ]
}

# parent / rank는 전역변수로 선언
parent = {}
rank = {}

def find(node): 
    # path compression 사용
    # if node가 root 노드가 아니라면 --> find() 재귀로 돌려 root를 찾음
    if parent[node] != node:
        parent[node] = find(parent[node])
        
    # else return parent[node]
    return parent[node]


def union(node_v, node_u):
    # union-by-rank 사용
    # 1. node_u와 node_v 각각의 root 노드를 찾음
    root_u = find(node_u)
    root_v = find(node_v)
    
    # > if node_v의 트리길이 > node_u의 트리 길이  --> node_v의 root를 node_u에 붙힘
    if rank[root_v] > rank[root_u]:
        parent[root_u] = root_v
    else:
         # > else node_u의 root를  node_u에 붙힘
        #  > if node_u의 트리길이 == node_v의 트리 길이 --> node_u의 rank를 1 증가시킴
        parent[root_v] = root_u
        
        if rank[root_u] == rank[node_v]:
            rank[root_u] += 1
   
    
def make_set(node):
    # rank 와 parent의 배열을 초기화
    parent[node] = node
    rank[node] = 0
    

def kruskal(graph):
    # 1. 배열 초기화 (mst, rank, parent 배열 생성)
    MST = []
    
    for node in graph['vertices']:
        make_set(node)
    
    # 2. edge로 sorting 하기
    edges = graph['edges']
    edges.sort()
    
    # 3. 간선 찾기
    for edge in edges:
        weight, node_v, node_u = edge
    
    # > if node_u, node_v의 root 노드(find)가 같지 않으면(= 사이클이 아니면) -> union하고 MST에 최단 경로 삽입
        if find(node_v) != find(node_u):
            union(node_v, node_u)
            MST.append(edge)
            
    return MST

kruskal(graph)
