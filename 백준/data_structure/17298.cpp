#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    vector<pair<int, int> > pair;
    vector<int> v(num, -1);

    for(int i = 0; i < num; i++) {
        int value;
        cin >> value;

        if(pair.empty()) {
            pair.push_back(make_pair(value, i));

        } else {
            if(pair.back().first < value) {
                while(!pair.empty() && (pair.back().first < value)) {
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