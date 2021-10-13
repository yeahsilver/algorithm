#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int numbers[11] = {0, };

    for(int i = 0; i < s.size(); i++) {
        int idx = s[i]-'0';
        numbers[idx]++;
    }

    if((numbers[6] + numbers[9])%2 == 0) {
        int value = (numbers[6] + numbers[9])/2;
        numbers[6] = numbers[9] =  value;
    } else {
        int value = (numbers[6] + numbers[9])/2;

        if(numbers[6] > numbers[9]) {
            numbers[6] = value+1;
            numbers[9] = value;

        } else {
            numbers[6] = value;
            numbers[9] = value+1;
        }
    }
    
    int maxValue = 0;

    for(int i = 0; i < 11; i++) {
        if(maxValue < numbers[i]) {
            maxValue = numbers[i];
        }
    }

    cout << maxValue << '\n';
}