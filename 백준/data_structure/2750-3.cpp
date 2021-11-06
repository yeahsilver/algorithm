#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> numbers;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        numbers.push_back(value);
    }

    for(int i = 1; i < numbers.size(); i++) {
        int current = numbers[i];
        int prev = i-1;

        while((prev >= 0) && numbers[prev] > current) {
            numbers[prev+1] = numbers[prev];
            prev--;
        }

        numbers[prev+1] = current;        
    }

    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}