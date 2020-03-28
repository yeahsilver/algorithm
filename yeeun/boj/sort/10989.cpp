#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

int main(void){
	int N, n;
	cin >> N;
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < N; i++){
		cin >> n;
		arr[n]++;
		}	
		
	for(int i = 1; i <= 10000; i++){
		for(int j = 0; j < arr[i]; j++){
			cout<<i<<"\n";
			}
		}
	}
