#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s) {
    int answer = __INT_MAX__;

    if(s.size() == 1) {
        return 1;
    }

    for(int i = 1; i <= s.size()/2; i++) {
        string result = "";
        string tmp = s.substr(0, i);

        int count = 1;

        for(int j = i; j < s.size(); j+=i) {
            string current = s.substr(j, i);
            if(tmp == current) {
                count++;

            } else {
                if(count > 1) {
                    result += to_string(count) + tmp;
                } else {
                    result += tmp;
                }

                tmp = current;
                count = 1;
            }
        }

        if(count > 1) {
            result += to_string(count) + tmp;
        } else {
            result += tmp;
        }

        if(answer > result.size()) {
            answer = result.size();
        }
    }

    return answer;
}

int main(void) {
    // string s = "aabbaccc";
    // string s = "ababcdcdababcdcd";
    // string s = "abcabcdede";
    // string s = "abcabcabcabcdededededede";
    // string s = "xababcdcdababcdcd";
    // string s = "abcabcabc";
    // string s = "bbaabaaaab";
    // string s = "zzzbbabbabba";
    string s = "a";

    cout << solution(s) << '\n';
}