#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        unordered_map<string, int> map;

        for(int i = 0; i < num; i++) {
            string type, key;
            cin >> type >> key;

            map[key]++;
        }

        int answer = 1;

        for(auto it = map.begin(); it != map.end(); it++) {
            answer *= it->second+1;    
        }

        cout << answer-1 << '\n';
    }
}