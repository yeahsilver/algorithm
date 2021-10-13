#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int* arr = new int[N+1];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 앞의 데이터가 뒤 데이터보다 크면 수 전환

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << '\t';
    }
}