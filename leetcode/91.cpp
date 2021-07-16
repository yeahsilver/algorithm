#include <iostream>
#include <string>

using namespace std;

int numDecodings(string s) {
    int* dp = new int[s.size()+2];

    for(int i = 0; i < s.size()+2; i++) {
        // 0번째 1번째일 경우 경우의 수 1개
        if(i < 2) {
            dp[i] = 1;

            // 개수가 2개일 때 부터 비교
        } else {
            int value = s[i-2] -'0';

            // 가리키고 있는 수가 1~9이면
            if(value > 0 && value <= 9) {
                // 앞의 경우의 수와 동일
                dp[i] += dp[i-1];
            }

            // 두번째 이상의 문자를 가리키고 있다면
            if(i > 2) {
                // 이전 문자에 대한 값을 추출
                int num = stoi(s.substr(i-3, i-1));

                // 이전 문자가 10~26 범위에 있다면 조건 만족
                if(num >= 10 && num <= 26) {
                    dp[i] += dp[i-2];
                }
            }
        }
    }

   return dp[s.size()+1];
}

int main(void) {
    string s = "12";
    cout << numDecodings(s) << '\n';
}