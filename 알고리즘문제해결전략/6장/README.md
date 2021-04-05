# 6장 무식하게 풀기

## 도입

- #### 완전 탐색

  : 가능한 방법을 전부 만들어보는 알고리즘



## 재귀 호출과 완전 탐색

- #### 재귀 호출

  > 자신이 수행할 작업을 유사한 형태의 여러 조각으로 쪼갠 뒤 그 중 한 조각을 수행하고, 나머지를 자기 자신을 호출해 실행하는 함수.

  ```c++
  // 6.1 1부터 n까지의 합을 계산하는 반복 함수와 재귀 함수
  
  #include <iostream>
  
  using namespace std;
  
  int recursiveSum(int n){
      if(n == 1) {
          return 1;
      }
  
      return n + recursiveSum(n-1);
  
  }
  
  int main(void) {
      int n;
      cin >> n;
  
      int sum = 0;
  
      for(int i = 1; i <= n; i++) {
          sum+=i;
      }
  
      cout << sum << '\n';
  
      cout <<  recursiveSum(n) << '\n';
  }
  ```

  
  - 기저 사례(base case): 쪼개지지 않는 가장 작은 작업들

    

- #### 예제: 중첩 반복문 대체하기

  ```c++
  #include <iostream>
  #include <vector>
  
  using namespace std;
  
  // TODO
  // 1. 재귀를 받음
  // 2. vector.size() == n 이면 출력
  // 3. 아닐경우 picked의 값이 없으면 0을 시작점으로, 있으면 back()+1를 시작점으로.   
  // 4. for문을 돌려 push_back(i) 해준 뒤, recursive(picked) 재귀가 끝나면 vector.pop_back()
  
  int n, m;
  
  void printPicked(vector<int> picked) {
  
      for(int i = 0; i < picked.size(); i++) {
          cout << picked[i] << '\t';
      }
  
      cout << '\n';
  }
  
  void recursive(vector<int> picked) {
      if (picked.size() == m) {
          printPicked(picked);
          return;
      }
  
      int smallest = picked.empty() ? 0 : picked.back() + 1;
  
      for(int i = smallest; i < n; i++) {
          picked.push_back(i);
          recursive(picked);
          picked.pop_back();
      }
  }
  
  int main(void) {
      cin >> n >> m;
  
      vector<int> picked;
  
      recursive(picked);
  }
  ```

  

## 예제: 보글 게임 (문제 ID: BOGGLE, 난이도: 하)

- #### 1단계: 문제를 읽고 이해하기

  - 상하좌우 / 대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는 것

    

- #### 2단계 : 재정의 및 추상화

  - 상하좌우 / 대각선 => Dx[8], dy[8]이라는 배열을 만들어서 for문을 돌려(8번) 일치하는지 여부 확인하기

  - 이 때, 일치하면 x+dx[i], y+dy[i]값으로 함수를 호출하기

  - 계속 반복 후 모두 true가 나온다면 성공, 아니면 실패

    

- #### 3단계 계획 세우기

  - 기저 사례가 3가지가 존재할 수 있음

    - 좌표에 맞지 않는 값이 나오면 false
    - 좌표에 맞는 글씨가 나오지 않는다면 false 
    - 길이가 1이라면 true

  - 매개변수 -> string 변수, 좌표 x, y의 변수

  - for문을 돌릴 때, 다음 글자가 상하좌우 / 대각선에 있는지 확인 후 true 반환

    

- #### 4단계 계획 검증하기 

  - 시간복잡도

    - 최악의 경우: 마지막 글자가 존재하지 않는 경우
    - 탐색은 N-1단계로 진행됨. 이 때 상하좌우/대각선에 있는 단어를 확인하기 위해 for문을 8번 돎.

    ==> 8^(N-1) = O(8^N)

    

- #### 5단계: 계획 수행하기

  ```c++
  #include <iostream>
  #include <string>
  
  #define for(i, n) for(int i = 0; i < n; i++)
  
  using namespace std;
  
  string board[5];
  
  int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
  int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
  
  bool hasWord(string word, int x, int y) {
      if(x < 0 || x >= 5 || y < 0 || y >= 5 ) {
          return false;
      }
  
      if(board[x][y] != word[0]) {
          return false;
      }
  
      if(word.size() == 1) {
          return true;
      }
  
      for(i, 8) {
          int nX = x + dx[i];
          int nY = y + dy[i];
  
          if(hasWord(word.substr(1), nX, nY)) {
              return true;
          }
      }
      return false;
  }
  
  int main(void) {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      
      int test_case;
      cin >> test_case;
  
      while(test_case--) {
           for(i, 5) {
              for(j, 5) {
                  cin >> board[i][j];
              }
          }
  
          int n;
          cin >> n;
  
          while(n--) {
              string word;
              cin >> word;
  
              bool flag = false;
  
              for(i, 5) {
                  for(j, 5) {
                      if(board[i][j] == word[0]) {
                          flag = hasWord(word, i, j);
                          break;
                      }
                  }
                  if (flag) {
                      break;
                  }
              }
  
              if(flag) {
                  cout << word << ' ' << "YES\n";
              } else {
                  cout << word << ' ' << "NO\n";
              }
          }
      } 
  }
  ```

  



- #### 6단계: 회고하기

  - 단순히 재귀 호출을 돌려 해당 원소에 맞는 값이 들어있는지를 출력해주면 되는 문제였다. 
  - 상하좌우/대각선만큼 for문을 도는 방식은 BFS 방식과 유사하여 문제를 풀기 어렵지 않았다.
  - 매크로 함수를 사용하여 for문을 더욱 새롭게 만들어보았다. 불필요한 실수를 제거해주는 것 같아 좋은 것 같다.
  - 완전 탐색 (Brute-Force) 형식의 문제라 그런지 for문의 양이 너무 많았다. for문을 줄이며 시간 복잡도를 줄이는 것이 더 좋은 알고리즘을 짜는 방법이라고 생각한다. 아마 dynamic programming? 으로 풀면 조금 더 빠르게 풀 수 있을 것 같다라는 생각이 든다.

