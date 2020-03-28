#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
	int N, n;
	cin >> N;
	stack<int> st;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		
		if(s == "push"){
			cin >> n;
			st.push(n);
		} else if( s == "pop"){
			if(!st.empty()){
				cout<<st.top()<<"\n";
				st.pop();
				} else {
					cout<<"-1"<<"\n";
					}
			} else if( s == "size"){
				cout<<st.size()<<"\n";
			} else if ( s == "empty"){
				if(st.empty()){
					cout<<"1\n";
				} else {
					cout<<"0\n";
					}	
			} else if( s == "top"){
				if(!st.empty()){
					cout<<st.top()<<"\n";	
				} else {
					cout<<"-1\n";
					}
			}
			
	}
}
