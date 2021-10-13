#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> numbers;
    int arr[8001] = {0, };

    double sum = 0;   
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);

        sum+=value;
        arr[value+4000]++;
    }

    sort(numbers.begin(), numbers.end());

    // 1. 산술평균   
    cout << round(sum/n) << '\n';

    // 2. 중앙값   
    cout << numbers[n/2] << '\n';

    // 3. 최빈값   
    int maxValue = 0;
    int maxCount = 0;
    bool countSecond = false;

    for(int i = 0; i < 8001; i++) {
        if(maxCount < arr[i]) {
            maxValue = i;
            maxCount = arr[i];
            countSecond = false;
        } else if (maxCount == arr[i]) {
            if(!countSecond) {
                countSecond = true;
                maxValue = i;
            }
        }
    }

    cout << maxValue-4000 << '\n';

    // 4. 범위   
    if(numbers.size() > 1) {
        cout << numbers[numbers.size()-1]-numbers[0] << '\n';
    } else {
        cout << 0 << '\n';
    }
    
}