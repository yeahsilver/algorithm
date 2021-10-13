#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1-i;j++) cout<<" ";
        for(int k=0;k<2*i+1;k++){
            if(i==N-1||k==0) cout<<"*";
            else if(k==2*i) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
}