#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j = 1;j<=i;j++){
            cout<<"*";
        }
        for(int k = (N*2)-(i*2);k>=1;k--){
            cout<<" ";
        }
        for(int j = 1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i=N-1; i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }

        for(int k = 1;k<=(N*2)-(i*2);k++){
            cout<<" ";
        }

        for(int j=1;j<=i;j++){
            cout<<"*";
        }

        cout<<"\n";
    }
}
