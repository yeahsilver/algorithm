#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    getline(cin, s);

    int cnt = 0;

    for(int i = 0; i < s.size(); i++) {
        if(cnt == 0 && s[i] == 'U') {
            cnt++;
        } else if(cnt == 1 && s[i] == 'C') {
            cnt++;
        } else if(cnt == 2 && s[i] == 'P') {
            cnt++;
        } else if(cnt == 3 && s[i] == 'C') {
            cnt++;
        }
    }

    if(cnt == 4) {
        cout << "I love UCPC\n"; 
    } else {
        cout << "I hate UCPC\n";
    }

    return 0;
}