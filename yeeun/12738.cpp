// 미완성
#include <iostream>
using namespace std;

int main(void){
    long long N,n;
    long long max = 0;
    long long a[1000000001] = {};

    cin>> N;
    cin>> a[1];
    for(int i = 2; i<=N; i++){
        cin>>a[i];
        if(a[i] < n){
            
            max++;
        }
        else {
            auto iter = lower_bound(n+1, n+max, n);
        }
    }
}