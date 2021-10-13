#include <iostream>
#include <string>

using namespace std;

int main(void) {
    char character[4] = {'U', 'C', 'P', 'C'};
    string s;

    getline(cin, s);

    int cnt = 0;

    for(int i = 0; i < s.size(); i++) {
        if(cnt == 4) break;
        if(s[i] == character[cnt]) cnt++;
    }

    if(cnt == 4) {
        cout << "I love UCPC\n"; 
    } else {
        cout << "I hate UCPC\n";
    }

    return 0;
}