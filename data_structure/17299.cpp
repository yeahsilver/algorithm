#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int num;
    cin >> num;

    vector<pair<int, int> > pair;
    vector<int> v(num, -1);
    vector<int> numbers;
    unordered_map<int, int> map;

    for(int i = 0; i < num; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);

        map[value]++;
    }

    for(int i = 0; i < num; i++) {
        int value = numbers[i];

        if(pair.empty()) {
            pair.push_back(make_pair(value, i));

        } else {
            if(map[pair.back().first] <  map[value]) {
                while(!pair.empty() && (map[pair.back().first] < map[value])) {
                    int index = pair.back().second;
                    v[index] = value;
                    pair.pop_back();
                }

                pair.push_back(make_pair(value,i));

            } else {
                pair.push_back(make_pair(value,i));
            }
        } 
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}