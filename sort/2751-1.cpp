#include<iostream>
using namespace std;
int N,arr[1000001];
int *sorted;

void merge(int left, int right){
	int middle = (left + right) / 2;

	int i = left;
	int j = middle + 1;
	int k = left;
	while (i <= middle && j <= right)
	{
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++]; 
        } else{
			sorted[k++] = arr[j++];
        }
	}

	int tmp = i > middle ? j : i;
	
	while(k<=right) {
        sorted[k++] = arr[tmp++];
    }

	for (int i = left; i <= right; i++){
        arr[i] = sorted[i];
    }
}

void partition(int left,int right){
	int middle;
	if (left < right)
	{
		middle = (left + right) / 2;
		partition(left, middle);
		partition(middle + 1, right);
		merge(left, right);
	}
}

int main(){
	cin >> N;
	sorted = new int[N];
	
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

	partition(0, N - 1);

	for (int i = 0; i < N; i++){
        cout << arr[i] << '\n';
    }
}