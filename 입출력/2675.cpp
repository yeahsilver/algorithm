#include <iostream>
using namespace std;

int main(void){
    int t,r;
    string s;
    cin>>t;
    while(t--){
        cin>>r>>s;
        for(int i =0; i<s.size();i++){
            for(int j=0;j<r;j++){
                cout<<s[i];
            }
        }
        cout<<endl;
    }
}