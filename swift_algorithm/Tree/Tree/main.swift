//
//  main.swift
//  Tree
//
//  Created by 허예은 on 2021/06/30.
//

import Foundation

// String을 자르는 메소드를 사용하면 타입은 자동으로 String.SubString 형으로 변환도
//class Node {
//    var data: String.SubSequence
//    var left: String.SubSequence
//    var right: String.SubSequence
//
//    init(_ data: String.SubSequence, _ left: String.SubSequence, _ right: String.SubSequence) {
//        self.data = data
//        self.left = left
//        self.right = right
//    }
//}
//
//func preOrder(_ node: Node) {
//    print(node.data, terminator: "")
//
//    if node.left != "." {
//        preOrder(tree[String(node.left)]!)
//    }
//
//    if node.right != "." {
//        preOrder(tree[String(node.right)]!)
//    }
//}
//
//func inOrder(_ node: Node) {
//    if node.left != "." {
//        inOrder(tree[String(node.left)]!)
//    }
//
//    print(node.data, terminator: "")
//
//    if node.right != "." {
//        inOrder(tree[String(node.right)]!)
//    }
//}
//
//func postOrder(_ node: Node) {
//    if node.left != "." {
//        postOrder(tree[String(node.left)]!)
//    }
//
//    if node.right != "." {
//        postOrder(tree[String(node.right)]!)
//    }
//
//    print(node.data, terminator: "")
//}
//
//let n = Int(readLine()!)!
//
//var tree: [String: Node] = [:]
//
//for _ in 0..<n {
//    let input = readLine()!.split(separator: " ")
//    let data = input[0]
//
//    tree[String(data)] = Node(data, input[1], input[2])
//}
//
//preOrder(tree["A"]!)
//print()
//inOrder(tree["A"]!)
//print()
//postOrder(tree["A"]!)


