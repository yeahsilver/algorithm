#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    unordered_map<string, bool> um;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        um[s] = true;
    }

    int count = 0;

    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;

        if(um[s]) {
            count++;
        }
    }

    cout << count << '\n';
}
