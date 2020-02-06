#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void){
    int num;
    cin>>num;
    for (int i =0; i<num;i++){
        for (int j=0; j<i+1;j++)
            cout<<"*";
        cout<<"\n";
    }
}