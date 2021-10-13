#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
    1. string 2개 받기
    2. 마지막 수부터 int로 바꾼 후, 더하면 숫자가 나오는데, 
    3. 1의 자리 수 이상이면 올림 수를 저장한 후, 다음 수에 넣기 
    4. 둘 중 하나가 empty하면 나머지 수 다 더하기
    5. 숫자 뒤집기
*/

string add(string a, string b) {
    int sum = 0;
    string result = "";

    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum+= a.back()-'0';
            a.pop_back();
        }

        if(!b.empty()) {
            sum += b.back()-'0';
            b.pop_back();
        }

        result.push_back((sum%10)+'0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(void) {
    string a, b;
    cin >> a >> b;

    cout << add(a, b) << '\n';

    return 0;
}