#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 1000001

bool isPrime[MAX] = {false, };

void calculatePrime() {
    isPrime[0] = isPrime[1] = true;

    for(int i = 2; i <sqrt(MAX); i++) {
        if(isPrime[i] == false) {
            for(int j = i+i; j <= MAX; j+=i) {
                isPrime[j] = true;
            }
        }
    }
}

int main(void) {
    int testCase;
    cin >> testCase;

    calculatePrime();

    while(testCase--) {
        int value;
        cin >> value;

        bool* numbers = new bool[value+1];
        int count = 0;

        for(int i = 0; i <= value; i++) {
            numbers[i] = false;
        }

        for(int i = 0; i < value; i++) {
            if(!isPrime[i]) {
                int target = value - i;
                
                if(!isPrime[target]) {
                    if(!numbers[i] && !numbers[target]) {
                        count++;
                        numbers[i] = true;
                        numbers[target] = true;
                    }
                }
            }
        }

        cout << count << '\n';
    }
}