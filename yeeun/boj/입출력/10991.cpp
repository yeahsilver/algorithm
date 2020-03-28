#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N-i-1;j++) cout << " ";
        for (int k=0;k<2*(i+1)-1;k++)
            if (k%2==0)
                cout << "*";
            else
                cout << " ";
                
        cout << "\n";
    }
}
