#include <iostream>
#include <vector>

using namespace std;

int N;
int numbers[1000001];
int *sorted;

void merge(int left, int right) {
    int middle = (left+right)/2;
    int i = left;
    int j = middle+1;
    int k = left;

    while(i <= middle && j <= right) {
        if(numbers[i] <= numbers[j]) {
            sorted[k++] = numbers[i++];
        } else {
            sorted[k++] = numbers[j++];
        }
    }

    int tmp = i > middle ? j : i;

    while(k <= right) {
        sorted[k++] = numbers[tmp++];
    }

    for(int i = left; i <= right; i++) {
        numbers[i] = sorted[i];
    }
}

void partition(int left, int right) {
    int middle;

    if(left < right) {
        middle = (left+right)/2;
        partition(left, middle);
        partition(middle+1, right);
        merge(left, right);
    }
}

int main(void) {
    int N;
    cin >> N;

    sorted = new int[N];
    
    for(int i = 0; i < N; i++) {
        int value;
        cin >> numbers[i];
    }    

    partition(0, N-1);

    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
    
}