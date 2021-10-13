
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int convertAlphabet(char c, int number) {
    return c-'A'+10;
}

long long convert(string num, int number) {

    long long answer = 0;
    
    int count = 0;

    for(int i = num.size()-1; i >= 0; i--) {
        char value = num[i];

        if('0' <= value && value <='9') {
            answer += pow(number, count) * (value-'0');

        } else {
            answer += pow(number, count)*convertAlphabet(value, number);
        }
        count++;
    }

    return answer;
}   

int main(void) {
    int number;
    string str;
    cin >> str >> number;

    cout << convert(str, number) << '\n';
} 
