from collections import defaultdict
from heapq import *

def prim(edges, start_node):
    mst = []
    adjacent_edges = defaultdict(list)
    
    # 각 노드의 인접 노드 삽입
    for weight, n1, n2 in edges:
        adjacent_edges[n1].append((weight, n1, n2))
        adjacent_edges[n2].append((weight, n2, n1))
    
    # set 형태로 연결노드 공간 생성 
    # start_node를 후보노드로 지정
    # cnadidate node을 heap에 삽입
    connected_nodes = set(start_node)
    candidate_edge_list = adjacent_edges[start_node]
    heapify(candidate_edge_list)
    
    # candidate node가 없을 때 까지
    while candidate_edge_list:
        weight, n1, n2 = heappop(candidate_edge_list)
        # 연결되어있는 노드가 연결 노드가 아니라면 connected_nodes에 노드 추가 후 mst에 삽입
        if n2 not in connected_nodes:
            connected_nodes.add(n2)
            mst.append((weight, n1, n2))
            
            # 연결되어있는 노드의 연결되어있는 노드가 connected_nodes에 존재하지 않는다면 후보노드의 리스트를 heap에 삽입
            for edge in adjacent_edges[n2]:
                if edge[2] not in connected_nodes:
                    heappush(candidate_edge_list,edge)
    
    return mst
    
edges = [
    (7, 'A', 'B'), (5, 'A', 'D'),
    (8, 'B', 'C'), (9, 'B', 'D'), (7, 'B', 'E'),
    (5, 'C', 'E'),
    (7, 'D', 'E'), (6, 'D', 'F'),
    (8, 'E', 'F'), (9, 'E', 'G'),
    (11, 'F', 'G')
]

prim(edges, 'A')
