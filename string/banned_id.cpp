#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool visited[10] = {0, };
vector<int> caseNum[10];
set<string> s;

void dfs(int idx, int banned_size) {
    if(idx == banned_size) {
        string tmp = "";

        for(int i = 0; i < 10; i++) {
            if(visited[i]) {
                tmp += to_string(i);
            }
        }

        s.insert(tmp);
        return;
    }

    for(int i = 0; i < caseNum[idx].size(); i++) {
        int now = caseNum[idx][i];

        if(visited[now]) {
            continue;
        }

        visited[now] = 1;

        dfs(idx+1, banned_size);
        
        visited[now] = 0;
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    for(int i = 0; i < banned_id.size(); i++) {
        for(int j = 0; j < user_id.size(); j++) {
            if(banned_id[i].size() != user_id[j].size()) {
                continue;
            }

            bool isMatched = true;

            for(int k = 0; k < user_id[j].size(); k++) {
                if(banned_id[i][k] == '*') {
                    continue;
                }

                if(banned_id[i][k] == user_id[j][k]) {
                    continue;
                }

                isMatched = false;
                break;
            }

            if(isMatched) {
                caseNum[i].push_back(j);
            }
        }
    }

    dfs(0, banned_id.size());

    answer = s.size();

    return answer;
}

int main(void) {

    vector<string> user_id;
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");

    vector<string> banned_id;
    banned_id.push_back("fr*d*");
    banned_id.push_back("abc1**");
    
    cout << solution(user_id, banned_id) << '\n';
}
