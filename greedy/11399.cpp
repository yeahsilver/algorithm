#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;

int main(void){
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int* arr = new int(N);
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	
	for(int i = 1; i < N; i++){
		arr[i] += arr[i-1];
	}
	
	int result = 0;
	
	for(int i = 0; i < N; i++){
		result += arr[i];
	}
	
	cout << result << '\n';
}
