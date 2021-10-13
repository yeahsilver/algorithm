#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> v;

    v.reserve(n);

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int value = v.front();
    int idx = 0;

    int group = 0;

    while(1) {
        idx += value;
        value = v[idx];

        if(v.size()-1 <= idx) break;

        group++;
    }

    cout << group << '\n';

}