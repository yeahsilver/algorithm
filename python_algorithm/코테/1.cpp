#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int num, lazer;
    cin >> num >> lazer;

    vector<pair<int, pair<int, int> > > v;

    for(int i = 0; i < num; i++) {
        int location, height, type;
        cin >> location >> height >> type;

        v.push_back(make_pair(location, make_pair(height, type)));
    }

    sort(v.begin(), v.end());

    int stopShoot = -1;
    int shootSuccess = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second.first > lazer) {
            if(v[i].second.second == 1) {
                shootSuccess++;

            } else if (v[i].second.second == 2) {
                continue;
            } else if (v[i].second.second == 3) {
                stopShoot = v[i].first;
                break;
            }
        }
    }

    // for(int i = 0; i < num; i++) {
    //     cout << v[i].first << '\t' << v[i].second.first << '\t' << v[i].second.second << '\n';
    // }

    cout << stopShoot << ' ' << shootSuccess;
}