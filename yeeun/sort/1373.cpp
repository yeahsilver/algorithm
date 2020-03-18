#include <iostream>
#include <string>

using namespace std;

int main(void){
    string s;
    cin >> s;
    string str; 
    if (s.size() % 3 == 1) str.append("00");
    else if (s.size() % 3 == 2) str.append("0");
        
    str = str.append(s);

    for(int i = 0; i< s.size(); i+=3){
        cout<<(str[i] -'0') * 4 + (str[i+1]-'0') * 2  + (str[i+2]-'0');
    }
}