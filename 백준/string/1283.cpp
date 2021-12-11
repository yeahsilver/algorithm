#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define MAX 31

using namespace std;

vector<string> split(string s, string del) {
    vector<string> v;
    int pos = 0;
    string token;

    while(s.find(del) != string::npos) {
        pos = s.find(del);
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos+del.length());
    }

    v.push_back(s);
    return v;
}

int main(void) {
    int num;
    cin >> num;
    cin.ignore(1, '\n');

    unordered_map<char, int> um;
    
    for(int i = 0; i < num; i++) {
        string s;
        getline(cin, s);

        bool flag = false;
        // 1. 왼쪽에서부터 오른쪽 순서로 단어의 첫글자가 이미 단축키로 지정되었는지 살펴보기
        string tmp = "";
        for(int i = 0; i < s.size(); i++) {
            int value = s[i];

            if(value == ' ') { 
                tmp += " "; continue; 
            }

            um[value]++;
            flag = true;
            tmp += '[' + value + ']';

            if(!um[value]) {
                
                
            } else {
                tmp += value;
            }
        }

        cout << tmp << '\n';    

        if(!flag) {
            vector<string> splited = split(s, " ");
        }

        

        
        

        // 2. 왼쪽부터 차례대로 알파벳을 보며 단축키로 지정 안된 것을 지정
        
    
    }
}