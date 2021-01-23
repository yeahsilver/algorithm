#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp (string a, string b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(void) {
    int N;
    cin >> N; 

    vector<string> words;

    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), cmp);
    words.erase(unique(words.begin(), words.end()), words.end());
    
    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }
}