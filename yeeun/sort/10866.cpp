#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void){
	int N;
	cin >> N;
	deque<int> d;
	string s;
	int n;
	
	for(int i = 0; i < N; i++){
		cin >> s;
		if(s == "push_front"){
			cin >> n;
			d.push_front(n);
		} else if (s == "push_back"){
			int n;
			cin >> n;
			d.push_back(n);
		} else if(s == "pop_front"){
			if(!d.empty()){
				cout<<d.front()<<"\n";
				d.pop_front();
			} else {
				cout<<"-1\n";
			}
		} else if (s == "pop_back"){
			if(!d.empty()){
				cout<<d.back()<<"\n";
				d.pop_back();
			} else {
				cout<<"-1\n";
			}
		} else if (s == "size"){
			cout<<d.size()<<"\n";
		} else if (s == "empty"){
			if(!d.empty()){
				cout<<"0\n";
			} else {
				cout<<"1\n";
			}
		} else if (s == "front"){
		 	if(!d.empty()){
		 		cout<<d.front()<<"\n";
		 	} else {
		 		cout<<"-1\n";
		 	}
		} else if (s == "back"){
			if(!d.empty()){
				cout<<d.back()<<"\n";
			} else {
				cout<<"-1\n";
			}
		}
	
	}
}
