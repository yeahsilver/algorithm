#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> numbers;
    
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;

        numbers.push_back(value);
    }

    int count = 0;

    if(numbers[0] == 1) {
        count++;
    }

    int left = 0;
    int right = 0;

    int mininumValue = __INT_MAX__;

    while(1) {
        if(right >= numbers.size()) {
            break;
        }

        if(count >= K) {
            int diff = right - left + 1;

            mininumValue = min(diff, mininumValue);

            if(numbers[left] == 1) {
                count--;
            }

            left++;

        } else if (count < K) {
            right++;

            if(right < numbers.size()) {
                if(numbers[right] == 1) {
                    count++;
                }
            }
        }

    }

    if(mininumValue == __INT_MAX__) {
        cout << -1 << '\n';
    } else {
        cout << mininumValue << '\n';
    }
}