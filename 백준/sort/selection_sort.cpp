#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int* arr = new int[N+1];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 1.제일 작은 값을 탐색
    // 2. 가장 앞에 있는 값에 넣기

    for(int i = 0; i < N; i++) {
        int minIdx = i;

        for(int j = i+1; j < N; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << '\t';
    }
}