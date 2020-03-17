//미완성

#include <iostream>
#include <string>

using namespace std;

int main(void){
    string s;
    cin >> s;
    string str; 
    if(s.size()%3 != 0){
        for(int i = 1; i < s.size()%3; i++){
            str.append("0");
        }
        str = str.append(s);
    }
    for(int i = 0; i< s.size(); i+=3){
        cout<<(str[i] -'0') * 4 + (str[i+1]-'0') * 2  + (str[i+2]-'0');
    }
}