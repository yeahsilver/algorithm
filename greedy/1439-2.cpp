#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;

int main(void) {
    string s;
    cin >> s;

    int zero = 0;
    int one = 0;

    for(int i = 0; i< s.length(); i++) {
        if(s[i] != s[i+1]) {
            if(s[i] == '0') {
                zero++;
            } else if(s[i] == '1') {
                one++;
            }
        }   
    }
    
    cout << min(zero, one) << '\n';
}