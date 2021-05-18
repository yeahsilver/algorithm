#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    int times = right - left;
    
    for(int i = left; i <= right; i++) {
        int cnt = 0;
        
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                cnt++;
            }2
        }
        
        if(cnt % 2 ==0) {
            answer += i;
        } else if (cnt %2 == 1) {
            answer -= i;
        }
    }
    return answer;
}

int main(void) {
    cout << solution(13, 17) << '\n';
}