#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, k, n ;
	cin >> N >> k;
	
	vector<int> v;
	
	for(int i = 0; i < N; i++){
		cin>>n;
		v.push_back(n);
		}	
		
		sort(v.begin(),v.end());
		
		cout<<v[k-1];
		
	}

