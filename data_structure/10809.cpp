#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    vector<int> alphabet(26, -1);

    for(int i = 0; i < str.size(); i++) {
        int idx = str[i]-'a';
        
        if(alphabet[idx] == -1) {
            alphabet[idx] = i;
        }   
    }

    for(int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
}