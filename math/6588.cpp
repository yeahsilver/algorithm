#include <iostream>
#include <vector>
#include <cmath>

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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;

    calculatePrime();

    bool isFind = false;

    while(num != 0) {  

        for(int i = 0; i < num; i++) {
            if(!isPrime[i]) {
                int target = num - i;
                
                if(!isPrime[target]) {
                    cout << num << " = " << i << " + " << target << '\n';

                    isFind = true;
                    break;
                }
            }
        }

        if(!isFind) {
            cout << "Goldbach's conjecture is wrong.\n";
        }

        cin >> num;
    }
}