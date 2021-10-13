#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int sum = s[0]-'0';

    for(int i = 1; i < s.size(); i++) {
        int operand = s[i]-'0';

        if(sum * operand > sum + operand) {
            sum*=operand;
        } else {
            sum+=operand;
        }
    }

    cout << sum << '\n';
}