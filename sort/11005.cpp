#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, B;
    cin >> N >> B;
    string s;

    while(N>0){
        int temp = N % B;
        if(temp < 10) s += (char)(temp +'0');
        else s += (char)(temp - 10 + 'A');
        N/=B;
    }

    reverse(s.begin(), s.end());
    cout<<s<<'\n';
}