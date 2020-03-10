#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	
	while(getline(cin,s)){
		int arr[4] = {0,};
	for(int i = 0; i < s.length(); i++){
		if(s[i]>= 97 && s[i] <= 122){
			arr[0]++;
			} 
		else if(s[i] >= 65 && s[i]<= 90) {
			arr[1]++;
		} else if(s[i] == ' '){ arr[3]++;}
		else arr[2]++; 
	}
		for(int i = 0; i < 4; i++){
		cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
}
