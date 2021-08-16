#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000001

int main(void) {
    int M, N;
    cin >> M >> N;
    
    bool check[MAX] = {false};
    check[1] = true;

    for(int i = 2; i < sqrt(MAX); i++) {
        if(check[i]) continue;

        for(int j = i+i; j < MAX; j+=i) {
            check[j] = true;
        }
    }

    for(int i = M; i <= N; i++) {
        if(!check[i]) {
            cout << i << '\n';
        }
    }
}