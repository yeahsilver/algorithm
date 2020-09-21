#include <iostream>

using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;

    int arr[N];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int MAX = 0;

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            for(int k = j; k < N; k++){
                if(i == j || j == k || i == k){
                    continue;
                }
                int temp = arr[i] + arr[j] + arr[k];
                if(temp <= M && MAX < temp){
                    MAX = temp;
                }
            }
        }
    }
    cout << MAX << '\n';
}