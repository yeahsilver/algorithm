#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string s = "";

    for(int i = 0; i < number.size(); i++) {
        // n^2라고 착각 할 수 있지만, number가 추가되는 것은 한번씩이기 때문에 n*2 정도로 해결할 수 있음
        while(!s.empty() && s.back() < number[i] && k > 0) { // 1개의 글자를 꺼냈을 때 지금 있는 글자 반복
            s.pop_back();
            k--;
        }

        if(k == 0) {
            s += number.substr(i, number.size()-i);
            break;
        }

        s.push_back(number[i]);
    }

    return s.substr(0, s.size()-k);
}

int main(void) {

    string number = "";
    int k;

    // number = "1924";
    // k = 2;

    // number = "1231234";
    // k = 3;

    number = "4177252841";
    k = 4;

    // number = "10000";
    // k = 2;

    cout << solution(number, k) << '\n';
}