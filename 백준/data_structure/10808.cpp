#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int alphabets[27] = {0, };

    for(int i = 0; i < str.size(); i++) {
        int idx = str[i]-'a';
        alphabets[idx]++;
    }

    for(int i = 0 ; i < 26; i++) {
        cout << alphabets[i] << ' ';
    }
}