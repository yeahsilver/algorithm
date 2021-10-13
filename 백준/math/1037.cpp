#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001

int arr[MAX];
int *sorted;

void merge(int left, int right) {
    int mid = (left+right)/2;

    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        } else {
            sorted[k++] = arr[j++];
        }
    }

    int tmp = i > mid ? j : i;

    while(k <= right) {
        sorted[k++] = arr[tmp++];
    }

    for(int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }

}

void partition(int left, int right) {
    int mid;

    if(left < right) {
        mid = (left+right)/2;
        partition(left, mid);
        partition(mid+1, right);

        merge(left, right);
    }
}

int main(void) {
    int n;
    cin >> n;
    sorted = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    partition(0, n-1);

    cout << arr[0]*arr[n-1] << '\n';

}