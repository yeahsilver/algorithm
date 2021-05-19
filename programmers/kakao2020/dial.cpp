#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define for(i, start, end) for(int i = start; i < end; i++)

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int leftHand = 10;
    int rightHand = 12;
    
    for(i, 0, numbers.size()) {
        // 왼손을 움직여야하는 경우
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            leftHand = numbers[i];
            answer.push_back('L');
        
        } else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) { // 오른손으로 움직여야하는 경우
            rightHand = numbers[i];
            answer.push_back('R');
            
        } else { // 왼손과 오른손을 선택해야하는 경우
            if (numbers[i] == 0) {
                numbers[i] = 11;
            }
        
            // 손과 해당 숫자의 차이를 구한다
            int leftDistance = abs(leftHand - numbers[i]);
            int rightDistance = abs(rightHand - numbers[i]);
            
            // 손과 해당 숫자의 거리를 구한다
            int leftToCurrent = (leftDistance / 3) + (leftDistance % 3);
            int rightToCurrent = (rightDistance / 3) + (rightDistance % 3);
            
            // 오른손이 더 가까이 있으면
            if(leftToCurrent > rightToCurrent) {
                rightHand = numbers[i];
                answer.push_back('R');
                
            } else if (leftToCurrent < rightToCurrent) { // 왼손과 더 가까이 있으면
                leftHand = numbers[i];
                answer.push_back('L');
                
            } else if (leftToCurrent == rightToCurrent) { // 왼손의 거리와 오른손의 거리가 같다면
                
                // 어느 손잡인지 체크하기
                if(hand == "right") {
                    rightHand = numbers[i];
                    answer.push_back('R');
                    
                } else if (hand == "left") {
                    leftHand = numbers[i];
                    answer.push_back('L');
                    
                }
            }
        }
    }
    return answer;
}