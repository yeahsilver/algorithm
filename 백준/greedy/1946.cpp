#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>  &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    int test_case;
    cin >> test_case;
    
    while(test_case--) {
        int n;
        cin >> n;

        int answer = 0;

        vector<pair<int, int> > rank;

        for(int i = 0; i < n; i++) {
            int first, second;
            cin >> first >> second;
            rank.push_back(make_pair(first, second));
        }

        sort(rank.begin(), rank.end());

        int minValue = __INT_MAX__;

        for(int i = 0; i < rank.size(); i++) {
            if(minValue > rank[i].second) {
                answer++;
                minValue = rank[i].second;
            }
        }

        cout << answer << '\n';
    }
}