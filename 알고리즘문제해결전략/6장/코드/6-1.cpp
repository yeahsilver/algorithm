#include <iostream>

using namespace std;

int recursiveSum(int n){
    if(n == 1) {
        return 1;
    }

    return n + recursiveSum(n-1);

}

int main(void) {
    int n;
    cin >> n;

    int sum = 0;

    for(int i = 1; i <= n; i++) {
        sum+=i;
    }

    cout << sum << '\n';

    cout <<  recursiveSum(n) << '\n';
}