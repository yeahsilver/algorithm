#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int number;
    cin >> number;

    vector<int> data;

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        data.push_back(value);
    }

    int max_value = INT_MIN;
    int sum = 0;

    for(int i = 0; i < number; i++) {
        sum = max(sum, 0) + data[i];
        max_value = max(sum, max_value);
    }

    cout << max_value << '\n';
}