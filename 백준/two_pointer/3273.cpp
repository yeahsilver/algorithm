#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> numbers;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        numbers.push_back(num);
    }

    int value;
    cin >> value;

    sort(numbers.begin(), numbers.end());

    int count = 0;

    int left = 0;
    int right = N-1;
    
    while(left < right) {
        int sum = numbers[left] + numbers[right];

        if(sum > value) {
            if(right > 0) {
                right--;
            }
        } else if(sum < value) {
            if(left < numbers.size()) {
                left++;
            }
        } else {
            count++;

            if(right > 0) {
                right--;
            }

            if(left < numbers.size()) {
                left++;
            }
        }
    }

    cout << count << '\n';

}