#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<int> num(11, 0);
    
    for(int i = 0; i < numbers.size(); i++) {
        int index = numbers[i];
        num[index] = 1;
    }
    
    for(int i = 0; i < 10; i++) {
        if(num[i] == 0) {
            answer += i;
        }
    }
    
    return answer;
}

int main(void) {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(0);

    cout << solution(numbers);
}