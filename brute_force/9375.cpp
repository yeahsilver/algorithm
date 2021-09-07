#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        vector<pair<string, string> > clothes;

        for(int i = 0; i < num; i++) {
            string cloth, style;
            cin >> cloth >> style;

            clothes.push_back(make_pair(cloth, style));
        }

        map<string, int> map;

        for(int i = 0; i < clothes. size(); i++) {
            string type = clothes[i].second;
            map[type]++;
        }

        int answer = 1;

        for(auto it = map.begin(); it != map.end(); it++) {
            answer *= (it->second+1);
        }

        cout << answer-1 << '\n';
    }
}
