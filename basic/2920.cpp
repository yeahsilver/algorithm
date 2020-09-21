#include <iostream>

using namespace std;

int main(void){
    bool ascending = true; 
    bool descending = true;
    int arr[8];

    for(int i=0; i < 8; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < 8; i++){
        if(arr[i-1] > arr[i]){
            ascending = false;
        }
        if(arr[i-1] < arr[i]){
            descending = false;
        }
    }

    if(ascending){
        cout << "ascending" << '\n';
    } else if(descending){
        cout << "descending" << '\n';
    } else {
        cout << "mixed" << '\n';
    }
}