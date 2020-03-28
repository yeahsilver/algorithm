#include <iostream>
using namespace std;


int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y,x % y);
} 

int lcm(int x, int y){
    return x*y/gcd(x,y);
}

int main(void){
    int N;
    cin>> N;
    int arr[1001] = { };

    for(int i = 0; i < N; i++){
        int x = 0; 
        int y = 0;
        cin >> x >> y;
        arr[i] = lcm(x,y);
    }

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<'\n';
    }

}