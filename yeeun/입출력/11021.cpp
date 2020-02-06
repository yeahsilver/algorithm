#include <iostream>
using namespace std;

int main(void){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int x, y;
        cin>>x>>y;
        cout<<"Case #"<<i<<": "<<x+y<<"\n"; 
    }
    return 0;
}