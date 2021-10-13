#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int add(int x){
    if (x==1) return 1;
    else return x+add(x-1);
}

int main(void){
    int num;
    cin>>num;
    cout<<add(num);
}