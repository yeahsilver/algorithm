#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();

    int turn = n-1;

    for(int i = 0; i < n; i++) {
        if(name[i]-'A' < 14) answer+= name[i]-'A';
        else answer +='Z'-name[i]+1;

        int idx = i+1;

        while(idx < n && name[idx] == 'A') answer++;

        turn = min(turn,  i+n-idx + min(i, n-idx));
    }

    answer += turn;
    return answer;
}

int main(void) {
    string name = "JEROEN";

    cout << solution(name);
}