#include <iostream>
using namespace std;

int arr[41]={1,1,};

int fibonacci(int n){
    if(n <= 1) return arr[n];
    else {
        if(arr[n] > 0) return arr[n];
    } return arr[n] = fibonacci(n-1) + fibonacci(n-2);
}
int main(void){
    int dp[41];
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;

        if(N == 0) cout<<"1 0\n";
        else if(N == 1) cout<<"0 1\n"; 
        else {
            fibonacci(N);
            cout<<arr[N-2]<<" "<<arr[N-1]<<'\n';
        }
    }
}