#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2000000000
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> numbers;

    for(int i = 0 ; i < N; i++) {
        int value;
        cin >> value;

        numbers.push_back(value);
    }

    sort(numbers.begin(), numbers.end());

    int left = 0;
    int right = N-1;
    int minimum = MAX;

    pair<int, int> answer;
    
    while(left < right) {

        int sum = numbers[left] + numbers[right];

        if(abs(sum) < minimum) {
            minimum = abs(sum);

            answer.first = numbers[left];
            answer.second = numbers[right];

            if(sum == 0) {
                break;
            }
        } 

        if(sum < 0) {
            left++;

        } else {
            right--;
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
}