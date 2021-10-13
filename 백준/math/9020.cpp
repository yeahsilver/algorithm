#include <iostream>
#include <cmath>

using namespace std;

#define MAX 10001

int main(void) {
    int testCase;
    cin >> testCase;

    bool check[MAX] = {false, };
    check[1] = true;

    for(int i = 2; i < sqrt(MAX); i++) {
        if(check[i]) continue;
        
        for(int j = i+i; j < MAX; j+=i) {
            check[j] = true;
        }
    }

    while(testCase--) {
        int n;
        cin >> n;

        int first = 0;
        int second = __INT_MAX__;

        for(int i = 2; i <= n; i++) {
            if(!check[i] && n-i >= i) {
                int index = n-i;

                if(!check[index] && second-first > index-i) {
                    first = i;
                    second = index;
                }
            }
        }

        cout << first << ' ' << second << '\n';
    }
}