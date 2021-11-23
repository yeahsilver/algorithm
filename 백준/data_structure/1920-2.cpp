#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    unordered_map<int, int> numbers;

    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        numbers[value]++;
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        int value;
        cin >> value;
        
        if(numbers[value]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}