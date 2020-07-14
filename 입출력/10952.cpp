#include <iostream>
using namespace std;

int main(void){
    int x,y;
    while(1){
        cin>>x>>y;
        if(x!=0 && y!=0){
            cout<<x+y<<"\n";
        }
        else {break;}
    }
    return 0;
}