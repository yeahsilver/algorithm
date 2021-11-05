#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> numbers(N);

    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i < N-1; i++) {
        int minIndex = i;

        for(int j = i+1; j < N; j++) {
            if(numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }

        int tmp = numbers[i];
        numbers[i] = numbers[minIndex];
        numbers[minIndex] = tmp;
    }

    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}