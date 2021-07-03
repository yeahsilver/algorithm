//
//  main.swift
//  BruteForce
//
//  Created by 허예은 on 2021/07/03.
//

import Foundation

// MARK: 모의고사
//func solution(_ answers: [Int]) -> [Int] {
//    var result: [Int] = []
//
//    let firstStudent = [1,2,3,4,5]
//
//    let secondStudent = [2,1,2,3,2,4,2,5]
//
//    let thirdStudent = [3,3,1,1,2,2,4,4,5,5]
//
//    var counts = [Int](repeating: 0, count: 3)
//
//    for i in 0..<answers.count {
//        if(answers[i] == firstStudent[i%5]) {
//            counts[0] += 1
//        }
//
//        if (answers[i] == secondStudent[i%8]) {
//            counts[1] += 1
//        }
//
//        if (answers[i] == thirdStudent[i%10]) {
//            counts[2] += 1
//        }
//    }
//
//    var max = 0
//
//    for i in 0..<counts.count {
//        if(max < counts[i]) {
//            max = counts[i]
//            result.removeAll()
//            result.append(i+1)
//
//        } else if(max == counts[i]) {
//            result.append(i+1)
//        }
//    }
//
//
//    return result
//}
//
//let answers = [1,3,2,4,2]
//print(solution(answers))

func solution(_ numbers: String) -> Int {
    
    func permutation(_ nowPermute: [String]) {
        
        if let number = Int(number) {
            if !results.contains(number) {
                
                if isPrime(number) {
                    results.append(number)
                }
            }
        }
        
        if nowPermute.count == numbers.count {
            return
        }
        
        for i in 0..<arr.count {
            if visited[i] {
                continue
                
            } else {
                visited[i] = true
                number += arr[i]
                permutation(nowPermute + [arr[i]])
                visited[i] = false
                number = ""
            }
        }
    }
    
    func isPrime(_ number: Int) -> Bool {
        if number < 2 {
            return false
        }
        
        for i in 2...Int(sqrt(Double(number)))+1{
            if(number%i == 0) {
                return false
            }
        }
        
        return true
    }
    
    var answer: Int = 0
    
    var visited: [Bool] = [Bool](repeating: false, count: numbers.count)
    var results: [Int] = []
    
    var arr = numbers.map {String($0)}
    var number: String = ""
    
    permutation([])
    
    return answer
}

let numbers = "011"

print(solution(numbers))
