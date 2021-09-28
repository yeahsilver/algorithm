#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> s[8];

    int base = 0;

    for(int i = 0; i < 8; i++) {
        base = 10 * base + 1;
        s[i].insert(base * N);
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < i; j++) {
            for(auto& op1: s[j]) {
                for(auto& op2: s[i-j-1]) {
                    s[i].insert(op1 + op2);
                    s[i].insert(op1 - op2);
                    s[i].insert(op1 * op2);

                    if(op2 != 0) {
                        s[i].insert(op1/op2);
                    }
                }
            }
        }

        if(s[i].count(number) > 0) {
            answer = i+1;
            break;
        }
    }

    return answer;
}

int main(void) {
    int N = 5;
    int number = 12;
    
    cout << solution(N, number) << '\n';
}