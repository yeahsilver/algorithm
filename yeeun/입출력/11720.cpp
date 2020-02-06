#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void){
    int num, sum=0;
    cin>>num;
    char* arr = new char[num];
    cin>>arr;
    
    for(int i=0; i<num;i++){
        sum+=arr[i]-'0';
    }
    delete[] arr;
    cout<<sum;
}