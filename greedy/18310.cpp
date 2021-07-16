#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    vector<int> town;

    // O(N)
    for(int i = 0; i < num; i++) {
        int house;
        cin >> house;
        town.push_back(house);
    }

    // O(NlogN)
    sort(town.begin(), town.end());

    int begin = 0;
    int end = num-1;

    int mid = (begin + end)/2;
    
    cout << town[mid] << '\n';

    return 0;
}