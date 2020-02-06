#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;

    for(int i=N; i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}