//
//  main.swift
//  BFS&DFS
//
//  Created by 허예은 on 2021/07/03.
//

import Foundation

// MARK: 타겟넘버 - 프로그래머스
//func solution(_ numbers: [Int], _ target: Int) -> Int {
//
//    var answer = 0
//
//    func dfs(_ depth: Int, _ sum: Int) {
//        if depth == numbers.count {
//            if target == sum {
//                answer+=1
//            }
//            return
//        }
//
//        dfs(depth+1, sum + numbers[depth])
//        dfs(depth+1, sum - numbers[depth])
//    }
//
//    dfs(0, 0)
//
//    return answer
//}
//
//let numbers = [1, 1, 1, 1, 1]
//let target = 3
//
//print(solution(numbers, target))

// MARK: 네트워크 - 프로그래머스
//
//func solution(_ n: Int, _ computers:[[Int]]) -> Int {
//
//    var visited = [Bool](repeating: false, count: computers.count)
//    
//    func bfs(_ n: Int, _ computers: [[Int]], _ start: Int) {
//        var need_visit = [Int]()
//        need_visit.append(start)
//
//        visited[start] = true
//
//        while !need_visit.isEmpty {
//            let now = need_visit.first
//
//            need_visit.removeFirst()
//
//            for i in 0..<computers[now!].count {
//                let next = computers[now!][i]
//
//                if(!visited[i] && (next != 0)) {
//                    need_visit.append(i)
//                    visited[i] = true
//                }
//            }
//        }
//
//    }
//
//    func connect(_ n: Int, _ computers: [[Int]]) -> Int {
//        var count = 0
//
//        for i in 0..<n {
//            if(!visited[i]) {
//                bfs(n, computers, i)
//                count+=1
//            }
//        }
//
//        return count
//    }
//
//    return connect(n, computers)
//}
//
//let n = 3
//let computers = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
//print(solution(n, computers))
