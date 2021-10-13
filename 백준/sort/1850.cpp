#include <iostream>
using namespace std;

long long gcd(long long x, long long y){
    if(y == 0) return x;
    else return gcd(y,x % y);
} 


int main(void){
    long long x, y;
    cin >> x >> y;
    long long result = gcd(x,y);

    for(int i = 0; i < result; i++){
        cout<<"1";
    }

}