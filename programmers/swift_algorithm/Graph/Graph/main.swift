//
//  main.swift
//  Graph
//
//  Created by 허예은 on 2021/07/01.
//

import Foundation

// MARK: 1260번 DFS와 BFS

//func DFS(graph: [Int: [Int]], start: Int) -> [Int] {
//    var visited: [Int] = []
//    var need_visit: [Int] = [start]
//
//    while !need_visit.isEmpty {
//        let node = need_visit.popLast()!
//        if visited.contains(node) {
//            continue
//        }
//
//        visited.append(node)
//        need_visit += graph[node] ?? []
//    }
//
//    return visited
//}
//
//func BFS(graph: [Int: [Int]], start: Int) -> [Int] {
//    var visited: [Int] = []
//    var need_visit: [Int] = [start]
//
//    while !need_visit.isEmpty {
//        let node = need_visit.remove(at: 0)
//
//        if visited.contains(node) {
//            continue
//        }
//
//        visited.append(node)
//
//        need_visit += graph[node] ?? []
//    }
//
//    return visited
//}
//
//let firstInput = readLine()!.split(separator: " ").map(){Int(String($0))!}
//let n = firstInput[0]
//let m = firstInput[1]
//let v = firstInput[2]
//
//var graph = [Int: [Int]]()
//
//for _ in 0..<m {
//    let value = readLine()!.split(separator: " ").map(){Int(String($0))!}
//    let start = value[0]
//    let end = value[1]
//
//    if graph[start] == nil {
//        graph[start] = [end]
//    } else {
//        graph[start]?.append(end)
//    }
//
//
//    if graph[end] == nil {
//        graph[end] = [start]
//    } else {
//        graph[end]?.append(start)
//    }
//}
//
//for key in graph.keys {
//    graph[key]?.sort(by: >)
//}
//
//var dfsResult = ""
//
//for i in DFS(graph: graph, start: v) {
//    dfsResult += String(i) + " "
//}
//
//for key in graph.keys {
//    graph[key]?.sort(by: <)
//}
//
//var bfsResult = ""
//
//for i in BFS(graph: graph, start: v) {
//    bfsResult += String(i) + " "
//}
//
//print(dfsResult)
//print(bfsResult)
//

// MARK: 2178 미로 탐색
//
//func BFS() -> Int {
//    var need_visit: [[Int]] = [[0, 0]]
//    
//    let dx: [Int] = [0, 0, -1, 1]
//    let dy: [Int] = [-1, 1, 0, 0]
//    
//    while !need_visit.isEmpty {
//        let current = need_visit.removeFirst()
//        
//        let cx = current[0]
//        let cy = current[1]
//        
//        for i in 0..<4 {
//            let nx = cx + dx[i]
//            let ny = cy + dy[i]
//            
//            if  nx < 0 || nx >= N || ny < 0 || ny >= M {
//                continue
//            }
//            
//            if graph[nx][ny] == 0 {
//                continue
//            }
//            
//            if graph[nx][ny] == 1 {
//                graph[nx][ny] = graph[cx][cy] + 1
//                need_visit.append([nx, ny])
//            }
//            
//        }
//    }
//    
//    return graph[N-1][M-1]
//    
//}
//
//let firstInput = readLine()!.split(separator: " ").map(){Int(String($0))!}
//let (N, M) = (firstInput[0], firstInput[1])
//
//var graph = [[Int]]()
//
//for _ in 0..<N {
//    graph.append(readLine()!.map{Int(String($0))!})
//}
//
//let answer = BFS()
//
//print(answer)


//func BFS(graph: [Int: [Int]], start: Int) -> [Int] {
//    var visited: [Int] = []
//    var need_visit: [Int] = [start]
//
//    while !need_visit.isEmpty {
//        let node = need_visit.remove(at: 0)
//
//        if visited.contains(node) {
//            continue
//        }
//
//        visited.append(node)
//
//        need_visit += graph[node] ?? []
//    }
//
//    return visited
//}

// MARK: 가장 먼 노드 - 프로그래머스 (다시 풀기)
//
//func solution(_ n: Int, _ edge: [[Int]]) -> Int {
//    var answer: [Set<Int>] = [[1]]
//    var connection = [[Int]]()
//    var visited = [Bool]()
//
//    func findConnection(_ n: Int, _ currentLine: Int) -> Set<Int> {
//        if answer.count == currentLine {
//            answer.append([])
//        }
//
//        for number in connection[n] {
//            if !visited[number] {
//                answer[currentLine].insert(number)
//            }
//        }
//
//        return answer[currentLine]
//    }
//
//    connection = Array(repeating: [Int](), count: n+1) // 어느 곳과 연결되어있는지 저장
//    visited = Array(repeating: false, count: n+1) // 방문 여부 확인
//
//    // connection 저장
//    edge.forEach {
//        connection[$0[0]].append($0[1])
//        connection[$0[1]].append($0[0])
//    }
//
//    // 현재 방문한 노드들
//    var currentNodes: Set = [1]
//
//    // 현재 노드 거리
//    var current = 1
//
//    while !currentNodes.isEmpty {
//        var nodes = Set<Int>()
//
//        // 노드 방문 체크
//        currentNodes.forEach {
//            visited[$0] = true
//        }
//
//        for node in currentNodes {
//            // 노드를 현재 노드와 비교해서 리턴값을 nodes 배열에 삽입
//            findConnection(node, current).forEach {
//                // 연결되어있는 노드를 삽입
//                nodes.insert($0)
//            }
//        }
//
//        current += 1
//        currentNodes = nodes
//
//        print()
//    }
//
//    answer.removeLast()
//
//    return answer.last?.count ?? 0
//}
//
//let n = 6
//let vertex = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
//
//print(solution(n, vertex))

// MARK: 순위 - 프로그래머스
func solution(_ n: Int, _ result: [[Int]]) -> Int {
    
    return 0
}


let n = 5
let result = [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]

print(solution(n, result))
