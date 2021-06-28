//
//  main.swift
//  Hash
//
//  Created by 허예은 on 2021/06/28.
//

import Foundation

// MARK: 완주하지 못한 선수
//var participants: Array<String> = ["leo", "kiki", "eden"]
//
//var completion: Array<String> = ["eden", "kiki"]
//
//participants.sort()
//completion.sort()
//
//for i in 0..<completion.count {
//    if participants[i] != completion[i] {
//        print(participants[i])
//        exit(0)
//    }
//}
//
//print(participants[participants.count-1])

// MARK: 전화번호 목록
//var phone_book = ["119", "97574223", "1195524421"]
//
//phone_book.sort()
//
//for i in 0..<phone_book.count-1 {
//    if phone_book[i+1].contains(phone_book[i]) {
//        print(false);
//        exit(0)
//    }
//}
//
//print(true)


// MARK: 위장
//var clothes = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]
//
//var answer: Int = 1
//
//var dic = [String: Int]()
//
//for cloth in clothes {
//    if dic[cloth[1]] != nil {
//        dic[cloth[1]]! += 1
//    } else {
//        dic[cloth[1]] = 1
//    }
//}
//
//for (_, value) in dic {
//    answer *= (value + 1)
//}
//
//print(answer-1)


// MARK: 베스트앨범
var genres = ["classic", "pop", "classic", "classic", "pop"]
var plays = [500, 600, 150, 800, 2500]

var answer: [Int] = []
var dic: [String: [[Int]]] = [:]

for i in 0..<genres.count {
    if dic[genres[i]] != nil {
        dic[genres[i]]?.append([i, plays[i]])
    } else {
        dic[genres[i]] = [[i, plays[i]]]
    }
}

// first.value와 second.value의 합을 통해 dic을 정렬한다.
let sorted = dic.sorted(by: { (first, second) -> Bool in
    return first.value.map{$0[1]}.reduce(0, +) > second.value.map{$0[1]}.reduce(0, +)
})


// value를 plays 기준으로 내림차순 정렬. play값이 같다면 인덱스가 작은 값이 먼저 오도록 작성
for i in 0..<sorted.count {
    let item = sorted[i].value.sorted(by: {(first, second) -> Bool in
        return first[1] == second[1] ? false : first[1] > second[1]})
    
    print(item)
    
    for i in 0..<item.count {
        if i > 1 {
            break
        }
        
        answer.append(item[i][0])
    }
}

print(answer)
