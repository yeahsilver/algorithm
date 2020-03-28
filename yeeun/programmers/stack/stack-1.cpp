//코딩테스트 연습 > 스택/큐 >탑
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    for(int i = heights.size(); i >= 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(heights[i] < heights[j]) {
                answer[i] = j+1;
                break;
            }
        }
    }

    return answer;
}   

int main(void){
    vector<int> v = solution({6,9,5,7,4});
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<' ';
    }
}