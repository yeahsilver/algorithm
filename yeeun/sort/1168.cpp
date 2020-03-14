// 미완성 

#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N, K;
	cin >> N, K;
	vector<int> v;
	
	for(int i = 1; i <= N; i++){
		v.push_back(i);	
	}  
	
	int remove = K-1;
	int copyN = N;
	
	cout<<"< ";
	
	for(int i = 0; i < N; i++){
		cout<<v[remove];
		if(i == N-1){
			cout<<" >";
		} else {
			cout<<", ";
		}
		
		v.erase(v.begin() + remove);
		remove += (K - 1);
		
		if(--copyN > 0){
			remove % copyN;
		}
	}
}
