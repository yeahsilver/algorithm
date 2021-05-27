#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
    규칙
    - S: 1제곱
    - D: 2제곱
    - T: 3제곱
    - *: 해당 점수와 바로 전에 얻은 점수를 각 2배
        처음 나오면 처음에만 2배
        중첩 가능. 중첩되면 4배
    - #: 해당 점수 마이너스
    - *와 # 중첩: -2배
*/
int solution(string dartResult) {
    int answer = 0;
    int index = 0;

    vector<int> num;

    
    for(int i = 0; i < dartResult.size(); i++) {
        if(dartResult[i] == 'S') {
            num[index-1] = pow(num[index-1], 1);

        } else if(dartResult[i] == 'D') {
            num[index-1] = pow(num[index-1], 2);

        } else if(dartResult[i] == 'T') {
            num[index-1] = pow(num[index-1], 3);

        } else if(dartResult[i] == '*') {
            num[index-1] = num[index-1] * 2;

            if(index > 1) {
                num[index-2] = num[index-2] * 2;
            }
        } else if(dartResult[i] == '#') {
            num[index-1] = num[index-1] * -1;
        } else {
            if(dartResult[i+1] == '0') {
                num.push_back(10);
                i++;

            } else {
                num.push_back(dartResult[i]-'0');
            }

            index++;
        }
    }

    for(int i = 0; i < num.size(); i++) {
        answer += num[i];
    }

    return answer;
}

int main(void) {
    string dartResult = "1S2D*3T";

    cout << solution(dartResult) << '\n';
}

