#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, n;
	while(cin >> x){
		x*=1e7;
		cin >> n;
		vector<int> v;
		
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		
		int left = 0, right = n-1;
		
		while(left < right){
			int total = v[left] + v[right];
		
			if(total == x){
				break;
			} else if (total < x){
				left++;
			} else {
				right--;
			}
		}
		if(left >=right){
			cout<<"danger";
		} else{
		cout<<"yes"<<" "<<v[left]<<" "<<v[right]<<'\n';
		}
	}
}
