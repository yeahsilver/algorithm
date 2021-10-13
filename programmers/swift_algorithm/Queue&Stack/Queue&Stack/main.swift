//
//  main.swift
//  Queue&Stack
//
//  Created by 허예은 on 2021/07/02.
//

import Foundation

// 각 배포마다 몇개의 기능이 배포되는지 return
// 모든 값을 계속 키우고 100이되면 pop
// 이 때 뒤의 것도 확인해서 되면 cnt

// MARK: 기능개발 (Programmers)
//func solution(_ progresses: [Int], _ speeds: [Int]) -> [Int] {
//
//    var answer = [Int]()
//
//    var queue = progresses
//    var speed = speeds
//
//    while(!queue.isEmpty) {
//
//        for i in 0..<queue.count {
//            let progress = queue[0]
//
//            queue.removeFirst()
//            queue.append(progress + speed[i])
//        }
//
//        var cnt: Int = 0
//
//        while (!queue.isEmpty && queue[0] >= 100) {
//            queue.removeFirst()
//            speed.removeFirst()
//            cnt+=1
//        }
//
//        if cnt > 0 {
//            answer.append(cnt)
//        }
//
//    }
//
//    return answer
//}
//
//let progresses = [93,30, 55]
//let speed = [1,30,5]
//
//print(solution(progresses, speed))

// MARK: 프린터 (Programmers)
// A B C D
// 2 1 3 2

/*
 1. 첫번째 A. 중요도가 젤 높은 수가 아니라 pop한 후에 다시 뒤로 들어감
 2. B도 마찬가지
 3. C가 우선 순위가 가장 높으니 들어가지 않아도 됨. pop!
 4. 그 후 D! pop!
 5. 그 후 A! POP!
 6. 그 후 B! POP!
    
*/

//func solution(_ priorities: [Int], _ location: Int) -> Int {
//    var queue = [[Int]]()
//    var priorityQueue = [Int]()
//
//    for i in 0..<priorities.count {
//        queue.append([i, priorities[i]])
//        priorityQueue.append(priorities[i])
//        priorityQueue.sort { return $0 > $1}
//    }
//
//    var cnt = 0
//
//    while true {
//
//        if priorityQueue.first! == queue[0][1] {
//
//            cnt+=1
//
//            if location == queue[0][0] {
//                break
//            }
//
//            queue.removeFirst()
//            priorityQueue.removeFirst()
//
//
//        } else {
//            let first = queue[0][0]
//            let second = queue[0][1]
//
//            queue.removeFirst()
//
//            queue.append([first, second])
//
//        }
//    }
//
//    return cnt
//}
//
//let priorities = [2,1,3,2]
//let location = 2
//
//print(solution(priorities, location))

// MARK: 다리를 지나는 트럭 (프로그래머스)

func solution(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
    
    var need_go = truck_weights
    var going = [[Int]]()
    var bridge_truck_weight = 0
    var time = 0
    
    while true {
        // 건너가는 트럭이 있다면
        if !going.isEmpty {
            // 다리를 건너왔으면 트럭을 queue 안에서 빼야함
            let first_truck_weight = going[0][0]
            let crossing_length = going[0][1]
            
            if crossing_length == bridge_length {
                
                bridge_truck_weight -= first_truck_weight
                going.removeFirst()
            }
        }
        
        // 가야할 트럭이 더 있을 때
        if !need_go.isEmpty {
            
            let next_truck_weight = need_go.first!
            
            // 다음 트럭의 무게가 다리가 버틸 수 있는 무게보다 작다면
            if bridge_truck_weight + next_truck_weight <= weight {
                
                // 다음 트럭 다리로 출발
                going.append([next_truck_weight, 0])
                
                // 다음 트럭에 대한 무게 추가
                bridge_truck_weight += next_truck_weight
                
                // 다음 트럭이 도로에 진입하였으니 가야할 트럭의 리스트에서 값을 빼줌
                need_go.removeFirst()
            }
        }
        
        // 반복문을 돌릴 때 마다 다리를 1씩 더 지나감
        for i in 0..<going.count {
            going[i][1] += 1
        }
        
        time+=1
        
        // 탈출 조건: 가야할 트럭도 없고 가고 있는 트럭도 없을 경우
        // => 모든 트럭이 다리에서 지나간 경우
        if going.isEmpty && need_go.isEmpty {
            break
        }

    }
    
    return time
}


//let bridge_length = 2
//let weight = 10
//let truck_weights = [7,4,5,6]

//let bridge_length = 100
//let weight = 100
//let truck_weights = [10]

let bridge_length = 100
let weight = 100
let truck_weights = [10,10,10,10,10,10,10,10,10,10]

print(solution(bridge_length, weight, truck_weights))
