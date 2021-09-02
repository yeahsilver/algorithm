#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Number {
    int numerator; // 분자
    int denominator; // 분모
};

Number reduction(int x, int y) {
    Number number;

    int minValue = min(x, y);

    for(int i = minValue; i > 0; i--) {
        if(x%i == 0 && y%i == 0) {
            number.numerator = x/i;
            number.denominator = y/i;

            break;
        }
    }

    return number;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> wheels;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        wheels.push_back(value);
    }

    int first = wheels.front();

    for(int i = 1; i < n; i++) {
        Number number = reduction(first, wheels[i]);
        cout << number.numerator << '/' << number.denominator << '\n';
    }

    return 0;
}