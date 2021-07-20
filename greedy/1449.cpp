#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, L;
    cin >> N >> L;

    vector<int> leaks;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        leaks.push_back(value);
    }

    sort(leaks.begin(), leaks.end());

    int point = leaks.front();
    int count = 0;

    L--;

    for(int i = 0; i < leaks.size(); i++) {
        int distance = leaks[i] - point;

        if (distance >= L) {
            count++;
            point = leaks[i+1];

        } else if(distance == 0) {
            count++;
        } 
    }
    cout << count << '\n';
}