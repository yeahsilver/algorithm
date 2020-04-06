#include <iostream>
#include <algorithm>
using namespace std;

int count(int x, int n){
    int temp = 0;
    for(int i =1; i <=n; i++){
        temp +=min(x/i,n);
    }
    return temp;
}

int main(void){
    int N,k;
    int cnt = 0;
    int result = 0;
    
    cin >> N >> k;
    
    int low = 1, high = k;
   

    while (low <= high){
        int mid = (low + high)/2;
        cnt = count(mid, N);
        if(cnt < k){
            low = mid + 1;
        } else{
            result = mid;
            high = mid - 1;
        }
    }
    cout<<result;
}