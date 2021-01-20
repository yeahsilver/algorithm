#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    int cnt = 0;
    vector<pair<int, int> > v;

    cin >> num;

    for(int i = 0; i < num; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    sort(v.begin(), v.end());

    int temp = 0;

    for(int i = 0; i < num; i++){
        int start = v[i].second;
        int end = v[i].first;

        if(start >= temp){
            temp = end;
            cnt++;
        }
    }

    cout << cnt << '\n';
}