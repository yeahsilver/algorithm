#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> numbers(N);

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);
    }

    int left = 0;
    int right = 0;
    int sum = numbers[0];
    int count = 0;

    while(1) {
        if(right >= numbers.size()) {
            break;
        }

        if(sum < M) {
            right++;

            if(right < numbers.size()) {
                sum += numbers[right];
            }

        } else if(sum > M) {
            sum -= numbers[left];
            left++;

        } else if (sum == M) {
            sum -= numbers[left];
            left++;
            right++;

            if(right < numbers.size()) {
                sum += numbers[right];
            }

            count++;
        }
    }

    cout << count << '\n';
}