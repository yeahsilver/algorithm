#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int main(void) {
    int N, S;
    cin >> N >> S;

    vector<int> numbers;

    for(int i = 0; i < N; i++) {
        int value;
        
        cin >> value;
        numbers.push_back(value);
    }

    int left = 0;
    int right = 0;
    int sum = numbers[0];
    int min = MAX;

    while(1) {
        if(right >= numbers.size()) {
            break;
        }

        if(sum < S) {
            if(right < numbers.size()) {
                right++;
                sum += numbers[right];
            }

        } else if (sum >= S){
            int diff = right - left + 1;

            if(min > diff) {
                min = diff;
            }

            sum -= numbers[left];
            left++;
        }
    }

    min == MAX ? cout << 0 << '\n' : cout << min << '\n';
}