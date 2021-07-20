#include <iostream>

using namespace std;


int main(void) {
    long long N;
    cin >> N;

    long long sum = 0;
    long long count = 0;

    for(long long int i = 1; ; i++) {
        sum+=i;
        if(sum > N) {
            cout << i-1 << '\n';
            break;
        }
    }
    
    return 0;
}