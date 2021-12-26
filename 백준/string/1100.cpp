#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int count = 0;
    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'F') {
                if(i%2 == 0 && j%2 == 0) {
                    count++;
                } else if(i%2 == 1 && j%2 == 1) {
                    count++;
                }
            }
        }
    }

    cout << count << '\n';
}