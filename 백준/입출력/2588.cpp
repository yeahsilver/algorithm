#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int num = B;

    while(num != 0){
        cout << A * (num % 10) << '\n';
        num/=10;
    }    
    
    cout << A * B << '\n';
}