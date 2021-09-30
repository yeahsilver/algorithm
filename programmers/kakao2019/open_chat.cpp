#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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


vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> map;

    vector<vector<string> > logs;

    for(int i = 0; i < record.size(); i++) {
        vector<string> parsedData = split(record[i], " ");
        logs.push_back(parsedData);

        string status = parsedData[0];
        string uid = parsedData[1];

        if(status != "Leave") {
            string nickname = parsedData[2];
            map[uid] = nickname;
        }
    }

    for(int i = 0; i < logs.size(); i++) {
        string status = logs[i][0];
        string uid = logs[i][1];

        auto find = map.find(uid);
        string nickname = find->second;

        if(status == "Enter") {
            string sentence = nickname + "님이 들어왔습니다.";
            answer.push_back(sentence);
        } else if(status == "Leave") {
            string sentence = nickname + "님이 나갔습니다.";
            answer.push_back(sentence);
        } else {
            continue;
        }
         
    }

    return answer;
}

int main(void) {
    vector<string> record;

    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");

    vector<string> result = solution(record);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}