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

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N-i; j++) {
            if(numbers[j-1] > numbers[j]) {
                int tmp = numbers[j-1];
                numbers[j-1] = numbers[j];
                numbers[j] = tmp;
            }
        }   
    }
    
    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}