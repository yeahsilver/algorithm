#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash;
    
    for(int i = 0; i < phone_book.size(); i++) {
        hash[phone_book[i]] = 1;
    }

    for(int i = 0; i < phone_book.size(); i++) {
        string str;

        for(int j = 0; j < phone_book[i].size(); j++) {
            str += phone_book[i][j];

            if(hash[str] && str != phone_book[i]) {
                return false;
            }
        }
    }
    
    return true;
}

int main(void) {
    vector<string> v;

    v.push_back("119");
    v.push_back("97674223");
    v.push_back("1195524421");

    cout << solution(v) << '\n';
}

