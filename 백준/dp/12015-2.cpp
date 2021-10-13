#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int num;
    int cnt = 0;
    cin >> num;

    vector<int> v;
    v.push_back(0);

    for(int i = 0; i < num; i++) {
        int value; 
        cin >> value;

        if(value > v.back()) {
            v.push_back(value);
            cnt++;
        } else {
            auto iter = lower_bound(v.begin(), v.end(), value);
            *iter = value;
        }
    }
    cout << cnt << '\n';
}