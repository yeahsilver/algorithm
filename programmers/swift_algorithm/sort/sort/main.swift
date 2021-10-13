//
//  main.swift
//  sort
//
//  Created by 허예은 on 2021/07/03.
//

import Foundation

// MARK: 가장 큰 수 - K번째 수
//func solution(_ array:[Int], _ commands: [[Int]]) -> [Int] {
//
//    var answer: [Int] = []
//
//    for command in commands {
//        let start = command[0]-1
//        let end = command[1]-1
//        let location = command[2]-1
//
//        let number = Array(array[start...end]).sorted()[location]
//
//        answer.append(number)
//    }
//
//    return answer
//}
//
//let array = [1, 5, 2, 6, 3, 7, 4]
//let command = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
//
//print(solution(array, command))

// MARK: 가장 큰 수 - 프로그래머스
// Int를 String형으로 변환하여 첫번째 글자만 확인하여 값 넣기
//
//func solution(_ numbers:[Int]) -> String {
//
//    var numbersString: [String] = []
//    var answer: String = ""
//
//    for index in numbers {
//        numbersString.append(String(index))
//    }
//
//    print(numbersString)
//
//    for _ in 0..<numbersString.count {
//        numbersString.sort(){ return $0 + $1 > $1 + $0}
//    }
//
//    for num in numbersString {
//        answer+=num
//    }
//
//    return answer
//
//}
//
//let numbers = [6, 10, 2]
//print(solution(numbers))

