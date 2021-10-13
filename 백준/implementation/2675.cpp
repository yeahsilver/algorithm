#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int R;
        string S;
        cin >> R >> S; 

        string answer = "";

        for(int i = 0; i < S.size(); i++) {
            for(int j = 1; j <= R; j++) {
                answer+=S[i];
            }
        }
        
        cout << answer << '\n';
    }
}