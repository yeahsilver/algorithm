#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

void quickSort(int start, int end) {
    if(start >= end) { return; }

    int pivot = start;
    int left = start;
    int right = end;

    while(left <= right) {
        // 원소 값이 피봇 값보다 큰 경우 찾기
        while(numbers[left] < numbers[pivot]) {
            left++;
        }

        // 원소 값이 피봇 값보다 작은 경우 찾기
        while(numbers[right] > numbers[pivot]){
            right--;
        }

        // 엇갈리지 않았을 경우
        if(left <= right) {
            swap(numbers[left], numbers[right]);
            left++;
            right--;
        }
    }
    quickSort(start, right);
    quickSort(left, end);
}

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);
    }

    quickSort(0, N-1);

    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}