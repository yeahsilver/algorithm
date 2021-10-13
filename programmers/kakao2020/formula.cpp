#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> operand;
    vector<char> op;
    
    string num = "";

    for(int i = 0; i < expression.size(); i++) {
        char value = expression[i];
        
        if(value == '-' || value == '*' || value == '+') {
            operand.push_back(stoll(num));
            num = "";
            
            op.push_back(value);
            
        } else {
            num+= value;
        }
    }

    
    
    return answer;
}

int main(void) {
    string expression = "100-200*300-500+20";
    cout << solution(expression) << '\n';
}