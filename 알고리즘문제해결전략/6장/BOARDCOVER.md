# 문제: 게임판 덮기 (문제 ID: BOARDCOVER, 난이도: 하)

- #### 1단계 문제를 읽고 이해하기

  - 3칸짜리 L자 블록으로 게임판을 덮을 수 있는 모든 경우의 수 출력

    

- #### 2단계 재정의 및 추상화

  - 2차원 배열을 사용하여 board 구성

  - L자 블록의 모양을 3차원 배열로 표현

    

- #### 3단계 계획 세우기

  - board를 채우기 
  - 기저 상황
    - 채운 후 비어있는 칸 찾기 ( x = -1, y = -1해서 for문 돌려서 찾기)

  - 만약 x = -1이면 => y도 접근하지 못하기에 return 0 반환

  - 아니라면 L자 블록 shape에 맞는지 판별.

    - L자 블록에 맞지 않으면 return false
    - 맞으면 return true

  - 재귀 호출 이후 다시 판을 -1로 바꿈

    

- #### 4단계 계획 검증하기

  - 게임판에 있는 흰 칸의 수 => 50을 넘지 않음.

  - L자 블록 (3개를 채움) => 50/3 = 16번 채움

    => 상한: 4^16 = 2^32 (여기서 4는 L자 블록의 개수)

    

- #### 5단계 계획 수행하기

  ```c++
  #include <iostream>
  #include <cstring>
  
  #define MAX 20
  #define for(i, start, end) for (int i = start; i < end; i++)
  
  using namespace std;
  
  int board[MAX][MAX] =  {0, };
  
  int height, width;
  
  int shape[4][3][2] = {
      {{0, 0}, {1, 0}, {0, 1}},
      {{0, 0}, {0, 1}, {1, 1}}, 
      {{0, 0}, {1, 0}, {1, 1}},
      {{0, 0}, {1, 0}, {1, -1}}
  };
  
  bool set(int x, int y, int type, int delta) {
      bool ok = true;
  
      for(i, 0, 3) {
          int nX = x + shape[type][i][0];
          int nY = y + shape[type][i][1];
  
          if(nX < 0 || nY < 0 || nX >= height ||  nY >= width) {
              ok = false;
          } else if ((board[nX][nY]+=delta) > 1) {
              ok = false;
          }
      }
  
      return ok;
  }
  
  int cover() {
      int x = -1;
      int y = -1;
  
      for(i, 0, height) {
          for(j, 0, width) {
              if(board[i][j] == 0) {
                  x = i;
                  y = j;
                  break;
              }
          }
          if(x != -1) {
              break;
          }
      }
  
      if(x == -1) {
          return 1;
      }
  
      int count = 0;
  
      for(type, 0, 4) {
          if(set(x, y, type, 1)) {
              count += cover();
          }
  
          set(x, y, type, -1);
      }
  
      return count;
  }
  
  int main(void) {
      int test_case;
      cin >> test_case;
  
      while(test_case--) {
          memset(board, 0, sizeof(board));
  
          cin >> height >> width;
  
          for(i, 0, height) {
              for(j, 0, width) {
                  char value;
                  cin >> value;
  
                  value == '#' ? board[i][j] = 1 : board[i][j] = 0;
              }
          }
          cout << cover() << '\n';
      }
  }
  ```

  

- #### 6단계 회고하기

  - PICNIC 문제와 같이 x와 y에 -1을 채우면 모두 찾았다는 것을 의미하기에 1을 리턴하는 방식으로 사용할 수 있었다. 
  - 코딩을 하다가 segmentation fault가 떴는데, 이유가 `((board[nX][nY]+=delta) > 1)` 이 수식에 괄호 안쳐서였다. 이런 부분도 꼼꼼히 살펴보자.
  - 타일을 벗겨내는 과정에서 set(x, y, type, -1)과 같이 사용할 수 있다는 것을 알았다. 새로운 방식을 배운 것 같다.
  - ﻿ 그리고 값이 이상하게 나오는 경우가 있었는데 이유가 shape의 모양을 제대로 안주어서 이상한 값이 나온 것이였다. 왼쪽 위를 기준으로 shape의 모양을 그렸어야 했는데, 정사각형을 그린 후 그림 그대로 좌표 값 계산해서 코딩하여 실수했다...

  