#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;

bool binary_search(int value) {
    int left = 0;
    int right = N-1;
    int mid;

    while(left <= right) {
        mid = (left+right)/2;

        if(numbers[mid] > value) {
            right = mid-1;
        } else if (numbers[mid] < value) {
            left = mid+1;
        } else {
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);
    }
    
    sort(numbers.begin(), numbers.end());

    cin >> M;

    for(int i = 0; i < M; i++) {
        int value;
        cin >> value;
        cout << binary_search(value) << '\n';
    }
}