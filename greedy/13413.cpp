#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        int n;
        cin >> n;

        vector<char> before;
        vector<char> after;

        before.reserve(n);
        after.reserve(n);

        for(int i = 0; i < n; i++) {
            char value;
            cin >> value;
            before.push_back(value);
        }

        for(int i = 0; i < n; i++) {
            char value;
            cin >> value;
            after.push_back(value);
        }

        int black = 0;
        int white = 0;

        for(int i = 0; i < before.size(); i++) {
            if(before[i] == after[i]) continue;

            if(before[i] == 'B') black++;
            else if(before[i] == 'W') white++;
        }

        int tmp = black > white ? white : black;
        
        int result = 0;

        while(tmp--) {
            black--;
            white--;
            result++;
        }

        result += black + white;

        cout << result << '\n';
    }
}