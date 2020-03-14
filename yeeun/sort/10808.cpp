#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	string s;
	int arr[27] = {};
	cin >> s;
	
	for(int i = 0; i < s.length(); i++){
		arr[s[i]-'a']++;
	}	
	
	for(int i = 0; i < 26; i++){
		cout<<arr[i]<<" ";
	}
}
