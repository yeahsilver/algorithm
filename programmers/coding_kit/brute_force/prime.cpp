#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    set<int> primeNumber;

    do {
       for(int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0,i));
    
            if(isPrime(num)) primeNumber.insert(num);          
       }

    } while(next_permutation(numbers.begin(), numbers.end()));

    
    return primeNumber.size();
}

int main(void) {
    string numbers = "17";

    cout << solution(numbers);
}