#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N, k;
	cin >> N >> k;
	vector<int> v(N);

	for(int i = 0; i < N; i++){
		v[i] = i+1;
	}

	int index = 0;
	vector<int> vec;

	while(!v.empty()){
		index = (index + (k-1)) % v.size();
		vec.push_back(v[index]);
		v.erase(v.begin() + index);
	}

	cout<<"<";

	for(int i = 0; i < N; i++){
		cout<<vec[i];
		if(i < N-1) cout<<", ";
	}
	cout<<">";

}
