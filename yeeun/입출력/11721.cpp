#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char c[100];
    cin>>c;
    for(int i=0;i<strlen(c);i++){
        cout<<c[i];
        if(i%10==9){
            cout<<"\n";
        }
        
    }
}