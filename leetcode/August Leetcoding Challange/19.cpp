#include <iostream>

using namespace std;

/*
    문제: 숫자로 바꿀 수 있는 경우의 수 구하기

    예외 상황
    s의 사이즈가 1이고 s[0] = '0'이거나 s의 사이즈가 0일 경우

    맨 뒤부터 탐색
    0 이상인 경우 -> count += 다음 자리 되는지 count
    마지막에서 다음 자리가 1이거나 2이고 마지막 자리가 7 미만인 경우 다음 자리도 되는지 count

    탈출 조건
    1. string의 사이즈가 0 또는 1일 경우 1 반환
    2. s[0]이 0이면 0 반환
*/

class Solution {
    public: 
        int numDecodings(string s) {
            if(s.length() == 0 || s[0] == '0') {
                return 0;
            }

            if(s.length() == 1) {
                return 1;
            }

            int count1 = 1, count2 = 1;
            
            for(int i = 1; i < s.length(); i++) {
                int count = 0;

                if(s[i] > '0') {
                    count += count2;
                }

                if((s[i-1] == '1') || s[i-1] == '2' && s[i] < '7') {
                    count += count1;
                }

                count1 = count2;
                count2 = count;

            }

            return count2;
        }        
};

int main(void) {
    Solution solution;
    
    string s = "12";

    cout << solution.numDecodings(s) << '\n';
}