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

    for(int i = 1; i < N; i++) {
        int key = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > key) {
            key = arr[prev];
            prev--;
        }
        arr[prev] = key;
    }
  
}