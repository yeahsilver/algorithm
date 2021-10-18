#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<double> alphabet;

    for(int i = 0; i < n; i++) {
        double value;
        cin >> value;
        alphabet.push_back(value);
    }

    stack<double> numbers;
    
    for(auto& value: s) {
        if(value >= 'A' && value <= ('A'+ n)) {
            int index = value - 'A';
            numbers.push(alphabet[index]);

        } else {
            if(numbers.size() >= 2) {
                double second = numbers.top();
                numbers.pop();

                double first = numbers.top();
                numbers.pop();

                if(value == '+') {
                    numbers.push(first + second);
                } else if(value == '-') {
                    numbers.push(first - second);
                } else if(value == '*') {
                    numbers.push(first * second);
                } else if(value == '/') {
                    if(second != 0) {
                        numbers.push(first / (double) second);
                    }
                }
            }
        }
    }

    printf("%.2f", numbers.top());
}