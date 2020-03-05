#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        
    }
}


// #include <iostream>
// using namespace std;

// int arr[1000001] = {};
// int tmp[1000001] = {};


// void merge(int& arr, int& tmp, int start, int mid, int end){
//     for(int i = start; i < end; i++){
//         tmp[i] = arr[i];
//         }
//     int s1 = start;
//     int s2 = mid + 1;
//     int index = start;
//     while(s1 <= mid && s1 <= end){
//         if(tmp[s1] <= tmp[s2]){
//             arr[index] = tmp[s1];
//             s1++;
//         } else { 
//             arr[index] = tmp[s2];
//             s2++;
//         }
//         index++;

//         for(int i = 0;  i <= mid - s1; i++){
//             arr[index + i] = tmp[s1 + i];
//         }
//     }
// }

// void mergeSort(int& arr, int& tmp, int start, int end){
//     if(start < end){
//         int mid = (start + end) / 2;
//         mergeSort(arr,tmp,start,mid-1);
//         mergeSort(arr,tmp,mid,end);
//         merge(arr, tmp, start, mid, end);
//     }
// }

// int main(void){
//     int N;
//     cin>>N;
//     int start = 0;
//     int end = N;

//     for(int i = 0; i < N; i++){
//         cin>>arr[i];
//     }

//     mergeSort(arr,tmp,start,end);

//     for(int i = 0; i < N; i++){
//         cout<<arr[i]<<"\n";
//     }

// }