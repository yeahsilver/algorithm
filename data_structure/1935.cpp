#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

double calculate(char op, double first, double second) {
    if(op == '+') {
        return second + first;
    }  
    
    if(op == '-') {
        return second - first;
    }  
    
    if(op =='*') {
        return second * first;
    }  
    
    if(op == '/') {
        return second / first;
    }
}

int main(void) {
    int num;
    cin >> num;

    string str;
    cin >> str; 


    vector<double> numbers;
    
    for(int i = 0; i < num; i++) {
        double value;
        cin >> value;
        numbers.push_back(value);
    }

    stack<double> insertion;
    stack<double> tmp;

    double answer = 0.0;

    for(int i = 0; i < str.size(); i++) {
        char value = str[i];

        if(value >= 'A' && value <= 'Z') {
            int idx = value-'A';
            insertion.push(numbers[idx]);

        } else {
            double first = insertion.top();
            insertion.pop();
            double second = insertion.top();
            insertion.pop();

            insertion.push(calculate(value, first, second));
        }
    }
    printf("%.2f\n", insertion.top());
}