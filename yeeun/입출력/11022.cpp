#include <iostream>
using namespace std;

int main(void){
    int T;
    int x,y;
    cin>>T;
    for(int i=1;i<=T;i++){
        
        cin>>x>>y;
        cout<<"Case #"<<i<<": "<<x<<" + "<<y<<" = "<<x+y<<"\n";
    }

}