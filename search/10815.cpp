#include <iostream>
#include <algorithm>

using namespace std;

bool binary_search(int* arr, int len, int value){
	int start = 0;
	int end = len;
	int mid;
	
	while(end - start >= 0){
		mid = (start + end) / 2;
		
		if(value == arr[mid]){
			return 1;
		}
		
		if(arr[mid] < value){
			start = mid + 1;
		} else {
			end = mid -1;
		}
	}
	
	return 0;
}

int main(void){
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N;
	
	int* arr = new int[N+1];
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	cin >> M;
	
	for(int i = 0; i < M; i++){
		int value;
		cin >> value;
		
		cout << binary_search(arr, N, value) << ' ';
	}
}
