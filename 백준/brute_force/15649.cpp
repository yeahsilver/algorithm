#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 9

int N, M;

bool isVisited[MAX];

void permutation(int depth, string number, vector<char> numbers) {
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            cout << number[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for(int i = 0; i < numbers.size(); i++) {
        if(!isVisited[i]) {
            isVisited[i] = true;
            permutation(depth+1, number + numbers[i], numbers);
            isVisited[i] = false;
        }
        
    }
}

int main(void) {
    cin >> N >> M;

    vector<char> numbers;

    for(int i = 1; i <= N; i++) {
        char character = i+'0';
        numbers.push_back(character);
    }

    permutation(0, "", numbers);
}