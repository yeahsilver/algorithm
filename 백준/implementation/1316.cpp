#include <iostream>
#include <string>

using namespace std;

#define MAX 27

int main(void) {
    int testCase;
    cin >> testCase;

    int answer = 0;

    while(testCase--) {
        string s;
        cin >> s;

        bool isVisited[MAX] = {false, };
        bool isGroupWord = true;

        isVisited[s[0]-'a'] = true;

        for(int i = 1; i < s.size(); i++) {
            int index = s[i]-'a';

            if(!isVisited[index]) {
                isVisited[index] = true;

            } else {
                if(s[i-1] == s[i]) {
                    continue;
                } else {
                    isGroupWord = false;
                    break;
                }
            }
        }

        if(isGroupWord) {
            answer++;
        }
    }

    cout << answer << '\n';
}