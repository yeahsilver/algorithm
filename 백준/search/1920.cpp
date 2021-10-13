#include <iostream>
#include <algorithm>

using namespace std;

bool binary_search(int* arr,  int len, int value){
	int start = 0;
	int end = len -1;
	int mid;
	
	while (end - start >= 0){
		mid = (start + end) /2;
		
		if(arr[mid] == value) {
			return true;
		} 
		
		if(arr[mid] > value){
			end = mid -1;
		} else {
			start = mid + 1;
		}
	}
	return false;
	
}

int main(void){
	int N;
	cin >> N;
	
	int* A = new int[N+1];
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	sort(A,A+N);
	
	
	int M;
	cin >> M;
	
	int* value = new int[M+1];
	
	for(int i = 0; i < M; i++){
		cin >> value[i];
	}
	
	for(int i = 0; i < M; i++){
		cout << binary_search(A, N, value[i]) << '\n';
	}
}
