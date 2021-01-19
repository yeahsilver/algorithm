#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;

    if(num < 10){
        num *= 10;
    }

    int cnt = 0;
    int result = num;

    do {
        int first = num / 10;
        int second = num % 10;
        int total = first + second;
    
        num = (second * 10) + (total % 10);
        cnt++;

    } while(result != num);
    
    cout << cnt << '\n';
}