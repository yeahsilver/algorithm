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
