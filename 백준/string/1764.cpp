#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    // 듣도보도 못한 사람
    map<string, bool> um;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        um[s] = true;
    }

    vector<string> result;

    // 보도 못한 사람
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;

        if(um[s]) {
            result.push_back(s);
        }
    }

    cout << result.size() << '\n';

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}