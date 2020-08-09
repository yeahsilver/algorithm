#include <iostream>

using namespace std;

int main(void){
    int N;
    int cnt = 1;
    int total;
    int sum  = 0;

    cin >> N;

    total = N;

    while(total >= 1){
        if(total < cnt){
            cnt = 1;
        } else {
            total -= cnt;
            cnt++;
            sum++;
        }
    }
    cout << sum << '\n';
}