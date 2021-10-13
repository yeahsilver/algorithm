#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int start = 0;
    int end = s.size()-1;

    while(start <= end) {
        if(s[start++]!= s[end--]) {
            return false;
        }
    }

    return true;
}

bool isSkipPalindrome(string s, int start, int end, bool isSkip) {
    if(start > end) {
        return true;
    } else if(s[start] == s[end]) {
        return isSkipPalindrome(s, start+1, end-1, isSkip);
    } else if (isSkip) {
        return max(isSkipPalindrome(s, start+1, end, false), isSkipPalindrome(s, start, end-1, false));
    } else {
        return false;
    }
}

int getAnswer(string s) {
    if(isPalindrome(s)) {
        return 0;
    } else if(isSkipPalindrome(s, 0, s.size()-1, true)) {
        return 1;
    } else {
        return 2;
    }
}

int main(void) {
    
    int testCase;
    cin >> testCase;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(testCase--) {
        string s;
        cin >> s;
        cout << getAnswer(s) << '\n';
    }
    
}