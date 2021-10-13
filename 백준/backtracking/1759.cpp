#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 15

using namespace std;

int L, C;

vector<char> alphabet;

void password(int position, string str, int consonant, int vowel){
    if(str.size() == L){
        if(consonant < 2  || vowel < 1){
            return ;
        }
        cout << str << '\n';
    }

    for(int i = position; i < C; i++){
        if(alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u'){
            password(i+1, str + alphabet[i] , consonant, vowel+1);
        } else {
            password(i+1, str + alphabet[i] , consonant+1, vowel);
        }
    }
}

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;

    for(int i = 0; i < C; i++){
        char input;
        cin >> input;
        alphabet.push_back(input);
    }

    sort(alphabet.begin(), alphabet.end());

    password(0,"",0,0);
}