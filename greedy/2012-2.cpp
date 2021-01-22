#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int* rank = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> rank[i];
    }

    sort(rank, rank + N);

    long long total = 0;
    for(int i = 0; i < N; i++){
        total += abs(rank[i] - (i+1));
    }

    cout << total << '\n';
}