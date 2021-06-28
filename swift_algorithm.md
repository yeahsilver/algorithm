## 알고리즘 풀이 문제를 위한 Swift 요약 정리 





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



### 배열 순회하기

#### 순회하며 원소 참조

```swift
var arr = [1,2,3]
for n in arr {
	print(n)
}
```



#### 순회하며 원소와 인덱스 참조 - enumerated()

```swift
for (index, value) in arr.enumerated() {
	print("\(index), \(value)")
}
```



#### 인덱스로 순회

```swift
var arr = [1,2,3]

for i in 0..<arr.count {
	print(arr[i])
}

for i in arr.indices {
	print(arr[i])
}
```



#### 역순으로 순회

```swift
var arr = [1,2,3]

for i in 0..<arr.count.reverse() {
	print(arr[i])
}

for i in arr.indices.reverse() {
	sprint(arr[i])
}
```





#### 배열 거꾸로 출력

```swift
var arr = [1,2,3]
var arrReversed = arr.reversed() // arr.reverse()

for n in arrReversed {
	print(n)
}
```



</br>



### 문자열

#### 특정 문자 기준으로 분리하기 - split()

```swift
var str = "Hello World! Swift"
var strings = str.split(separator: " ")

print(strings)
```



#### 문자열 배열을 하나의 문자열로 합치기 - joined()

```swift
let arrHello = ["Hello", "World", "!"]
var hello = arrHello.joined()

hello = arrHello.joined(separator: " ") // Hello World !
hello - arrHello.joined(separator: ", ") // Hello, World, !
```



### 대/소문자 변경 - capitalized, uppercased(), lowercased()

```swift
var str = "abcdef"
str = str.capitalized // 첫번째만 대문자로 변경 "Abcdef"
str = str.uppercased() // 전체 대문자로 변경 "ABCDEF"
str = str.lowercased() // 전체 소문자로 변경 "abcdef"
```



#### 문자열 포함 체크 - contains()

```swift
var str = "abcdef"
str.contains("a") // true
str.contains("ab") // true
str.contains("cd") // true
str.contains("ac") // false
```



#### string 인덱스 다루기

```swift
var str = "abcdef"

str[str.startIndex] // "a"


// 세번째 문자 가져오기
let index = str.index(str.startIndex, offsetBy: 3-1) 
str[index] // "c"

let sub = str[str.startIndex...index] // "abc"

str.firstIndex(of: "c")

// 문자 검색해서 Index 찾기
"abc123".index(forstOf: "c")

// 특정 character replace
string.replaceOccurences(of: " ", with: "+")
```

</br>



### 비트 연산

#### 2진수로 변환했을 떄 1의 개수

```swift
let n: Int8 = 25
n.nonzeroBitCount // 3
```



</br>



### 수학

#### 제곱근 - sqrt()

```swift
// Double형 입력받아 Double형 반환
sqrt(4.0) // 2.0
```



</br>



### 거듭제곱 - pow()

```swift
// Double형 입력받아 Double형 반환
pow(2.0, 3.0) // 2^3 = 8
```





</br>



----



</br>



### 알고리즘에 필요한 Swift Basic 총정리

> https://twih1203.medium.com/swift-알고리즘에-필요한-swift-basic-총정리-d86453bbeaa5



</br>



### 키보드 입력

```swift
let value = readLine() // 이 때 return값은 Optional String

// split으로 입력 값 자르기
let nums = readLine()!.split(separator: " ") 
let nums = readLine()!.components(seperatedBy: " ") 
```



### Decimal을 Int로

```
(decimal as NSDecimalNumber).intValue
```



### 부동 소수점 다루기

#### NumberFormatter 이용

```
let formatter = NumberFormatter()
formatter.roundingMode = .down // 내림
formatter.minFractionDigits = 2 // 2자릿수까지마ㅏㄴ 표현
formatter.maxFractionDigits = 2

let num = formatter.string(from: NSNumber(value: 2.334532)) // 3.23
```





</br>



### 진수 표현

```swift
// 10진수 -> N진법
String(integer, radix: n)

// N진법 -> 10진수
Int("1100011", radix: n)!
```



</br>



### 문자를 ASCII코드로 변환

```swift
Character("a").asciiValue!
```



</br>



### String에 식이 들어있을 때 그대로 계산하기

```swift
let mathExpression = NSExpression(format: "3+4+2-1*6")
let mathValue = mathExpression.exrpessValue(with: nil, context: nil) as! Int // result: 3
```



### 절대값 변환

```swift
abs(-29) // 29
```



#### for문에서 원하는 수치만큼 증가 or 감소하는 반복문이 필요할 때

```swift
stride(from: 1, to: 5, by: 2) // open range 5 불포함 1,3까지만
stride(from: 1, through: 5, by: 2) // closed range. 5 포함 1 3. 까지
```



</br>



### Dictonary 사용하기

#### 1. 생성

```swift
var dic: [Int: String] = [:]
var dic: [Int: string]()

var dic = [1: "a", 2: "b", 3: "c"]
```



#### 2. 값 수정

```swift
dic.updateValue("c", forKey: 3)
dic[3] = "d"
```





#### 3. 값 추가

```swift
dic[4] = "5"
dic.update("5", forKey: 4) // 4라는 키가 있을 경우 수정이 됨
```



#### 4. 접근

```swift
dic[4]!			
```



#### 5. for문 돌기

```swift
for (key, value) in dic {
	print(key)
	print(value)
}

// 단, 순서는 뒤죽박죽이다!
```



#### 6. 값 삭제

```swift
dic.removeValue(forKey: 4) // 특정 키값 삭제
dic.removeAll() // 전체 삭제
```



#### 7. Key를 바꿀 경우, 지우고 다시 넣어줘야함



#### 8. Dictionary Key로 sort하기

```swift
let sort = dic.sorted(by: {$0.key < $1.key }) // value로 sort하는 경우
$0.value
```

