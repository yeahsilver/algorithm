#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 246913

int main(void) {

    bool check[MAX] = {false};
    check[1] = true;

    for(int i = 2; i < sqrt(MAX); i++) {
        if(check[i]) continue;

        for(int j = i+i; j < MAX; j+=i) {
            check[j] = true;
        }
    }


    while(1) {
        int n;
        cin >> n;

        if(n == 0) {
            break;
        }

        int count = 0;
        for(int i = n+1; i <= 2*n; i++) {
            if(!check[i]) {
                count++;
            }
        }

        cout << count << '\n';

    }
}