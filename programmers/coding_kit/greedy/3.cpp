#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int start = 0;
    int size = number.size()-k;

    for(int i = 0; i < size; i++) {
        int index = start;

        for(int j = start+1; j <= k+i; j++) {
            char value = number[j];

            if(number[index] < value) {
                index = j;
            }
        }
        
        start = index+1;
        answer += number[index];
    }

    return answer;
}

int main(void) {

    string number = "";
    int k;

    number = "1924";
    k = 2;

    // number = "1231234";
    // k = 3;

    // number = "4177252841";
    // k = 4;

    // number = "10000";
    // k = 2;

    cout << solution(number, k) << '\n';
}