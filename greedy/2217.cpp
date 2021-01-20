#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;

    int* W = new int[N];

    for(int i = 0; i < N; i++){
        cin >> W[i];
    }

    sort(W, W + N, greater<int>());

    int maxValue = 0;

    for(int i = 0; i < N; i++){
        maxValue = max(maxValue, W[i]*(i+1));
    }
    
    cout << maxValue << '\n';
}