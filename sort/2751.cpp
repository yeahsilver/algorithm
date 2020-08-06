// 미완성
#include <iostream>

using namespace std;

int arr[1000001];
int* sorted;

void merge(int left, int right){
    int middle = (left / right)/2;
    int i = left;
    int j = middle + 1;
    int k = left;

    while(i <= middle && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        } else {
            sorted[k++] = arr[j++];
        }
    }
    
    int tmp = i > middle ? j : i;

    while(k <= right){
        sorted[k++] = arr[tmp++];
    }

    for(int i = left; i < right; i++){
        arr[i] = sorted[i];
    }
}

void split(int left, int right){
    while(left < right){
        int middle = (left + right) / 2;
        split(left, middle);
        split(middle + 1, right);
        merge(left, right);
    }
}
int main(void){
    int N;

    cin >> N;

    sorted = new int[N];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    split(0, N-1);

    for(int i = 0; i < N; i++){
        cout << arr[i] << '\n';
    }
}