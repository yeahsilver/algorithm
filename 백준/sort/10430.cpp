#include <iostream>
#include <vector>

using namespace std;

int func1(int a, int b, int c){ return (a+b)%c; }

int func2(int a, int b, int c){ return (a % c + b % c) % c; }

int func3(int a, int b, int c){ return (a * b) % c; }

int func4(int a, int b, int c){ return (a % c * b % c)%c; }

int main(void){
    int A, B, C;
    int arr[4] = {};
    cin >> A >> B >> C;

    arr[0] = func1(A,B,C);
    arr[1] = func2(A,B,C);
    arr[2] = func3(A,B,C);
    arr[3] = func4(A,B,C);

    for(int i = 0; i < 4; i++){
        cout<<arr[i]<<"\n";
    }
}