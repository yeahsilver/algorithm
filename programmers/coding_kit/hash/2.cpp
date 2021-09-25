#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;
    
    for(auto& number: phone_book) {
       string s = "";
        
        for(auto& num: number) {
            s += num;

            if(map[s] != 0) {
                answer = false;
                break;
            }
        }

        map[number]++;
    }

    return answer;
}

int main(void) {
    vector<string> v;

    v.push_back("123");
    v.push_back("456");
    v.push_back("678");

    cout << solution(v) << '\n';
}