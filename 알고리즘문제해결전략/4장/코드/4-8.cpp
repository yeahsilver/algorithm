#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int number, int* arr) {
    for(int i = 0; i < number; i++) {
        int min_value = arr[i];
        int location = i;

        for(int j = i+1; j < number; j++) {
            if(min_value > arr[j]) {
                min_value = arr[j];
                location = j;
            }
        }
        swap(arr[i], arr[location]);
    }

    cout << "==== 선택 정렬 ====\n";

    for(int i = 0; i < number; i++) {
        cout << arr[i] << ' ';
    }
    
    cout << '\n';
}

void insertionSort(int number, int* arr) {
   // 두번째 요소를 선택 후 그보다 작은 요소들을 탐색해서 비교

    for(int i = 0; i < number; i++) {
        int key = i;

        for(int j = i-1; j >= 0; j--) {
            if (arr[key] < arr[j]) {
                swap(arr[key], arr[j]);
                key = j;
            } 
        }
    }

    cout << "==== 삽입 정렬 ====\n";

    for(int i = 0; i < number; i++) {
        cout << arr[i] << ' ';
    }
}

int main(void) {
    int number;

    cout << "배열의 크기를 입력하세요: ";
    cin >> number;

    int* arr1 = new int[number+1];
    int* arr2 = new int[number+1];

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        arr1[i] = value;
        arr2[i] = value;
    }

    selectionSort(number, arr1);
    insertionSort(number, arr2);
}