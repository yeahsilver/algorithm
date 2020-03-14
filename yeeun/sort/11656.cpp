#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	string s;
	string str[1001] = {};
	
	cin >>s;
	
	for(int i = 0; i < s.length(); i++){
		str[i] = s.substr(i,s.length());
	}
	
	int length = s.length();
	
	sort(str, str + length );
	
	for(int i = 0; i < s.length(); i++){
		cout<<str[i]<<'\n';
}
	
}
