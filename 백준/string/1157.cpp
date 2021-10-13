#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int alphabet[26] = {0,};

    string word;
    cin >> word;

    for(int i = 0; i < word.size(); i++) {

        // 대문자일경우
        if(word[i] >= 65 && word[i] <= 90) {
            int index = word[i]-65;
            alphabet[index]++;

        } else if(word[i] >= 97 && word[i] <=122){
            int index = word[i]-97;
            alphabet[index]++;
        }
    }

    int max_num = 0;
    char result;

    for(int i = 0; i < 26; i++) {
        if(max_num < alphabet[i]) {
            max_num = alphabet[i];
            result = i+65;

        } else if(max_num == alphabet[i]) {
            result = '?';
        }
    }    
    
    cout << result << '\n';
}