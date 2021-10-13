#include <iostream>
#include <string>

using namespace std;

bool isSuccess(int i, int n) {
    int sum = i;
    string s = to_string(i);

    for(int i = 0; i < s.size(); i++) {
        sum += s[i]-'0';
    }

    if(sum == n) {
        return true;
    }

    return false;
}

int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        if(isSuccess(i, n)) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
}