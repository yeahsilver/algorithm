#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;

    vector<int> numbers;
    for(int i = 0; i < num; i++) {
        int value;
        numbers.push_back(value);
    }

    sort(numbers.begin(), numbers.end());

    int sum = 0;

    for (int number: numbers) {
        sum+=number;
    }

    cout << sum << '\n';

    
}