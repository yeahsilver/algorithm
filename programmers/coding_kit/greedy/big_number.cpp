#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*
    예시) 1924
    19 12 14
    92 94
    24

    두개씩 묶어서 확인해야하기에 size = number.size()-k = 2;

    start = 0으로 선언한 후
    number[start] = 1을 maxNum에 넣고 start를 maxIdx에 삽입 (어디 인덱스일 때 가장 수가 높은지를 체크)

    k+i는 자르는 개수를 의미함.
    for문을 k+i만큼 돌려서 maxNum보다 크면 삽입.
    maxNum보다 크게된다면 maxIdx도 변한다는 것이기에, maxIdx도 변환

    큰 값을 찾았다면 그 다음으로 큰 값을 제일 큰 값 뒤에서 찾아야함.
    그래서 start = idx+1를 삽입후 다시 for문 돌림

*/

string solution(string number, int k) {
    string answer = "";

    int size = number.size()-k;
    int start = 0;

    for(int i = 0; i < size; i++) {
        char maxNum = number[start];

        int maxIdx = start;

        for(int j = start; j <= k+i; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }

        start = maxIdx+1;
        answer += maxNum;
    }

    return answer;
}

int main(void) {
    int k = 3;
    string number = "4177252841";

    cout << solution(number, k);
}