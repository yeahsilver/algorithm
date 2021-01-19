#include <iostream>
using namespace std;

int main(void){
    string s;
    int cnt = 1;
    getline(cin,s);
    for(int i =0; i<s.size();i++){
        if(s[i]==' ') cnt++;
    }
    cout<<s.size()<<'\n';
    if(s[0]==' ') cnt--;
    if (s[s.size()-1]==' ') cnt--;
    cout<<cnt;
}