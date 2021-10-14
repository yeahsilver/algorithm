#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 9

int N, M;

vector<int> v;

void permutation(int depth, int num) {
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++) {
        v.push_back(i);
        permutation(depth+1, i+1);
        v.pop_back();
    }
}

int main(void) {
    cin >> N >> M;

    vector<int> numbers;

    permutation(0, 1);
}