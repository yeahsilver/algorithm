#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int maxValue = 0;
    int maxIdx = 0;
    int count = 0;

    while(k>0) {
        string tmp = number.substr(maxIdx, k);
        cout << maxIdx << '\t' << maxIdx + k << '\n';
        cout << k << '\t' << tmp << '\n';
        
        for(int i = 0; i < tmp.size(); i++) {
            if(maxValue < tmp[i]) {
                maxValue = tmp[i];
                maxIdx = i;
            }
        }

        for(int i = 0; i < tmp.size(); i++) {
            if(maxValue > tmp[i]) {
                count++;
            }
        }

        k-=count;
        maxIdx++;

        answer += maxValue;
    }

    return answer;
}

int main(void) {
    string number = "4177252841";
    int k = 4;

    cout << solution(number, k) << '\n';

}