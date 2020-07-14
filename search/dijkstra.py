import heapq
def dijkstra(graph, start_node):
    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0
    
    queue = []
    heapq.heappush(queue, [distances[start_node], start_node])
    
    while queue:
        current_distance , current_node = heapq.heappop(queue)
        
        # 최단 거리가 이미 존재 할 때
        if distances[current_node] < current_distance:
            continue
        
        for adjacent, weight in graph[current_node].items():
            distance = current_distance + weight
            
            if distance < distances[adjacent]:
                distances[adjacent] = distance
                heapq.heappush(queue, [distance, adjacent])
                
    return distances

graph = {
    'A': {'B': 8, 'C': 1, 'D':2},
    'B': {},
    'C': {'B': 5, 'D': 2},
    'D': {'E': 3, 'F': 5},
    'E': {'F': 1},
    'F': {'A': 5}
    }

dijkstra(graph, 'A')
