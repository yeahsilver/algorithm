#include <iostream>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string convert2to8(string s) {
    int num = s.size()%3;

    if(num == 1) {
        s = "00"+s;

    } else if (num == 2) {
         s = "0"+s;
    }

    string answer = "";

    for(int i = 0; i < s.size(); i+=3) {
        int first = s[i]-'0';
        int second = s[i+1]-'0';
        int third = s[i+2]-'0';

        int sum = (first*4) + (second*2) + (third*1);
        answer += to_string(sum);
    }

    return answer;
}

int main(void) {
    string s;
    cin >> s;

    cout << convert2to8(s) << '\n';
}