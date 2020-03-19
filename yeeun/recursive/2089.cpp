#include <iostream>
using namespace std;

void change10to2(int num){
    if(num == 0) return ;
    if(num % -2 == 0) {
        change10to2(num/-2);
        cout<<"0";
    } else{
        change10to2((num-1)/-2);
        cout<<"1";
    }
    return;
}

int main(void){
    int N;
    cin >> N;
    if(N == 0)
        cout<<"0";
    change10to2(N);
}