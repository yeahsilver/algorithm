## 알고리즘 풀이 문제를 위한 Swift 요약 정리 

> https://kyungminleedev.github.io/notes/SwiftForAlgorighms/



### 배열

```swift
// 1차원 배열
var arr = [Int]() 
var arr: Array<Int> = [] 
var arr: [Int] = []

// 2차원 배열
varr arr4 = [[Int]]()
```





</br>



### 원소 크기 지정하여 배열 생성

```swift
var arr = Array(repeating: 1, count 5) // 5개의 칸을 1로 채우기
```





</br>



### 배열 정렬

```swift
var arr = [1,3,2]

// sort(): 배열이 정렬됨 (원본의 순서 변경)
// sorted(): 배열을 정렬한 배열을 반환 (원본은 변경 없음)

arr.sort() // 오름차순: [1,2,3]
arr.sort(by: >) // 내림차순: [3,2,1]
```





</br>



### 배열 다루기

```swift
var arr = [1,2,3,4,5]

// 인덱스로 원소 찾기
arr[2] // 3

// 원소로 인덱스 찾기 (옵셔널)
arr.firstIndex(of: 3)! // 2. => arr[?] = 3 

// 인덱스로 원소 지우기
arr.remove(at: 2) // [1,2,4,5]

// 맨 뒤에 새 원소 추가
arr.append(6) // [1,2,4,5,6]

// 맨 뒤 원소 지우고 반환
arr.removeLast() // [1,2,4,5]

// 특정 인덱스에 원소 넣기
arr.insert(3, at: 2) // [1,2,3,4,5]

// 특정 원소 있는지 확인
arr.contains(3) //true

// 순서 반전
arr.reverse() // [5,4,3,2,1] 

// 첫 원소 지우고 반환
arr.removeFirst()

// 첫 원소 반환 (옵셔널)
arr.first!

// 마지막 원소 지우고 반환
arr.popLast()

// 마지막 원소 반환 (옵셔널)
arr.last!

// 원소의 최대값, 최소값 (옵셔널)
var min = arr.min()! // 1
var max = arr.max()! // 5

// 모든 원소 지우기
arr.removeAll()


// 조건을 만족하는 모든 원소 지우기
arr.removeAll(where: {$0 % 2 == 0})

// 원소 스왑
arr.swapAt(_:, _:)
```



</br>



### 배열 추출

```swift
var arr: Array<Int> = [1,2,3,4]

arr[1...2] // [2,3]
arr[1...2] = [5,6,7,8,9]

print(arr) // [1,5,6,7,8,4]
```



</br>



### Map

```swift
var arrStr = ["1", "2", "3"]
var arrInt = arrStr.map{Int($0)!} // [1,2,3] 원소를 모두 Int형으로 반환
```



</br>



### Filter

> 조건식이 참인 원소만 필터링

```swift
var arr = [1,2,3,4,5]
var arrEven = arr.filter { $0 % 2 == 0 } // [2, 4]
var arrOdd = arr.filter { $0 % 2 == 1 } // [1,3,5]
```



</br>



### Reduce

```swift
var arr = [1,2,3]
arr.reduce(0, +) // 모든 원소 더하기 (0은 초기값)
arr.reduce(0, -1) // 모든 원소 빼기
```



</br>



