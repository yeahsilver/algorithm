#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isVPS(string s){
	stack<int> st;
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		
		if(c == '('){
			st.push(s[i]);
		} else {
			if(!st.empty()){
				st.pop();
			} else {
				return false;
			}
		}	
	}
	return st.empty();
}

int main(void){
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		
		if(isVPS(s)){
			cout << "YES" <<"\n";
		} else {
			cout << "NO" << "\n";
		}
		
	}	
}
	
	
