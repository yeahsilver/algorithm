#include <iostream>
using namespace std;

int main(void){
    int num;
    cin>>num;
    for(int i =1; i<=num; i++){
        int x,y;
        cin>>x>>y;
        if (x>0 && y <10){
            cout<<x+y<<"\n";
        }        
    }
    return 0;
}