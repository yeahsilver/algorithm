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

    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            int sum = 0;

            for(int k = i; k < j; k++) {
                sum += data[k];
            }
            max_value = max(max_value, sum);
        }
    }

    cout << max_value << '\n';

    max_value = INT_MIN;

    for(int i = 0; i < number; i++) {
        int sum = 0;

        for(int j = i; j < number; j++) {
            sum += data[j];
            max_value = max(max_value, sum);
        }  
    }

    cout << max_value << '\n';
}