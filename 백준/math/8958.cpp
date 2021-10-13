#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int correctCount = 0;
        int answer = 0;

        for(int j = 0; j < s.size();j++){
            if(s[j] == 'O') {
                correctCount++;
                answer += correctCount;
            } else if(s[j] == 'X') {
                correctCount = 0;
            }
        }

        cout << answer << '\n';
    }
}