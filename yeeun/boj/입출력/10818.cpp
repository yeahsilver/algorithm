#include <iostream>
using namespace std;

int main(void){
    int min = 1000000;
    int max = -1000000;
    int N,x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x<min) min = x;
        if(x>max) max = x;
    }

    cout<<min<<" "<<max;


}