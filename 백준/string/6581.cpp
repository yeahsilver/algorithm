#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    int word_length = 0;

    while(cin >> word) {

        if(word == "<br>") {
            cout << '\n';
            word_length = 0;

        } else if (word == "<hr>") {
            if(word_length != 0) {
                cout << '\n';
                word_length = 0;
            }

            for(int i = 0; i < 80; i++) {
                cout << '-';
            }

            cout << '\n';
            word_length = 0;

        } else {
           if(word_length + word.size() < 80) {
               if(word_length != 0) {
                   cout << ' ';
                   word_length++;
               }

               cout << word;
               word_length += word.size();
           } else {
               cout << '\n';
               word_length = 0;
               cout << word;
               word_length += word.size();
           }
        }
    }
}