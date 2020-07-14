#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long fibo(int x){
    long num1=0, num2=1, num3=0, sum=0;
     if (x == 0) return 0;

     else if (x==1) return 1;

     else {
         for (int i = 0; i<x; i++){
                num1 = num2;
                num2 = num3;
                num3 = num1+num2;
         }   
     }
     return num3;  
}

int main(void){
    int num;
    cin>>num;
    cout<<fibo(num);
    return 0;
}