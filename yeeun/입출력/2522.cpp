#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(N-i<=j-1)cout<<"*";
            else cout<<" ";
        }
       
        cout<<"\n";
    }

    for(int i=1;i<=N;i++){
         for(int k=0;k<N;k++){
            if(i-1<k)cout<<"*";
            else cout<< " ";
        }
        cout<<"\n";
    }
}