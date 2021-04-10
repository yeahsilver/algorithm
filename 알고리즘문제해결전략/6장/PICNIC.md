# 문제: 소풍 (문제 ID: PICNIC, 난이도: 하)

- #### 1단계 문제 읽고 이해하기

  - 친구끼리 짝을 지을 수 있는 경우의 수 출력

    

- #### 2단계 재정의와 추상화

  - 한 친구를 기준으로 그 친구의 짝이 되는 경우를 계산하기.

  - 이 때, 친구의 번호보다 큰 번호를 가질 때만 숫자 count하게 해야함. (중복 허용 불가)

  - 짝을 찾았으면 바로 다른 친구 짝 찾기.

    

- #### 3단계 계획 세우기

  - areFriends라는 배열을 만들고 친구인지 아닌지를 넣어서 체크하기.

  - 친구가 되었다면 친구 쌍을 true로 변환 후 접근하지 못하게 조건문 세우기

  - 기저 상황

    - 모든 학생이 짝을 찾았다면 1 리턴

      

- #### 4단계 계획 검증

  - 친구가 n명일 때 => n-1 * n-3 * n-5 * ... * 1 => n^(n/2)

    

- #### 5단계 계획 구현

  ```c++
  #include <iostream>
  #include <cstring>
  
  using namespace std;
  
  #define MAX 11
  #define for(i, start, n) for(int i = start; i < n; i++)
  
  int student, pair_number;
  
  bool areFriends[MAX][MAX];
  bool isChecked[MAX] = {0, };
  
  int countingPairs(){
      int count = 0;
      int firstFree = -1;
  
      // 체크하지 않은 친구의 번호를 for문을 통해 돌려 가지고오기
      for(i, 0, student) {
          if(!isChecked[i]) {
              firstFree = i;
              break;
          }
      }
  
      // 친구 모두르 체크했다면 1을 리턴함으로써 1가지 경우의 수가 만들어졌음을 알림
      if(firstFree == -1) {
          return 1;
      }
  
      // 다음 친구부터 체크 했는지 안했는지 확인 후에 체크하지 않았으면 해당 친구를 짝으로 타깃 설정 후 다른 짝을 찾음.
      for(i, firstFree+1, student) {
          if(!isChecked[i] && areFriends[firstFree][i]) {
              isChecked[firstFree] = true;
              isChecked[i] = true;
  
              count += countingPairs();
  
              // 1가지 경우의 수를 모두 찾은 뒤 실행되는 함수임.
              // isChecked에 대한 값을 false로 만들어 다음 경우의 수를 체크할 수 있게 만듦
              isChecked[firstFree] = false;
              isChecked[i] = false;
          }
      }
  
      return count;
  }
  
  int main(void) {
      cin.tie(NULL);
      ios_base::sync_with_stdio(false);
  
      int test_case;
      cin >> test_case;
  
      while(test_case--) {
          memset(areFriends, false, sizeof(areFriends));
          memset(isChecked, false, sizeof(isChecked));
  
          cin >> student >> pair_number;
  
          for(i, 0, pair_number) {
              int pair_first, pair_second;
              cin >> pair_first >> pair_second;
  
              areFriends[pair_first][pair_second] = true;
              areFriends[pair_second][pair_first] = true;
          }
  
          int result = countingPairs();
  
          cout << result << '\n';
      }
  
  }
  ```

  

- #### 6단계 회고하기

  - 짝을 모두 찾은 경우를 firstFree = -1로 체크하는 방법이 있구나를 깨달음. 
    - 재귀함수를 계속 호출하는 것이기에 호출된 새로운 함수에서 firstFree의 값이 -1일 것이고, isChecked[i]가 모두 true이면 firstFree가 계속 -1로 남아있기에 모두 방문하였다는 것을 알 수 있었음.

