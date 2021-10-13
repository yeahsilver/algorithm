#include <iostream>
#include <string> 
#include <vector>

using namespace std;

vector<string> split(string s, string del) {
    vector<string> v;
    int pos = 0;

    string token;
    
    while((s.find(del) != string::npos)) {
        pos = s.find(del);
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + del.length());
    }

    v.push_back(s);

    return v;
}

int main(void) {
    string str;
    getline(cin, str);

    vector<string> splited = split(str, " ");

    string first = splited[0] + splited[1];
    string second = splited[2] + splited[3];

    cout << stoll(first) + stoll(second) << '\n';

    return 0;
}