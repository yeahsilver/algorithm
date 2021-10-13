#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void){
	int N;
	cin >> N;
	queue<int> q;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		
		if(s == "push"){
			int n;
			cin >> n;
			q.push(n);
		} else if(s == "pop") {
			if(!q.empty()){
				int p = q.front();
				q.pop();
				cout<<p<<"\n";
			} else {
				cout<<"-1\n";	
			}
		} else if(s == "size"){
			cout<<q.size()<<"\n";
		} else if(s == "empty"){
			if(!q.empty()){
				cout<<"0\n";
			} else {
				cout<<"1\n";
			}
		} else if(s == "front"){
			if(!q.empty()){
				cout<<q.front()<<"\n";
			} else {
				cout<<"-1\n";
			}
		} else if(s == "back"){
			if(!q.empty()){
				cout<<q.back()<<"\n";
			} else {
				cout<<"-1\n";
			}
		} 
	}
}
