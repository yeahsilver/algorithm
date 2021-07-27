#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string s = "";
    for(int i = 0; i < n; i++) {
        char value;
        cin >> value;
        s+=value;
    }

    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        sum += s[i]-'0';
    }

    cout << sum << '\n';
}