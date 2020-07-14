#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    int T;
    cin >> T;
    while(T--){
        long long N;
        cin >> N;
        long long result = ((-1)+sqrt(pow(1,2)-(4*1*(-2*N))))/2;
        cout << result << '\n';
    }
}
