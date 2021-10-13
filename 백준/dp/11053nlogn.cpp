// 미완성
#include <iostream>
using namespace std;

int main(void){
    int N;
    int max = 0;
    int a[1001] = {};
    int dp[1001] = {};
    cin>>N;

    int low = 1;
    int high = N;
    int mid;
    
    for(int i = 1; i <= N;i++){
        cin>>a[i];
    }

    while (low <= high) {
        mid = (low - high) / 2;
        for(int i = 1; i<=N; i++){
            if(a[mid] == a[i])
                return mid;
            else if(a[mid] > a[i]) high = mid - 1;
            else low = mid + 1;
        }  
    } 

    for(int i = 1; i <= N; i++){
        cout<<a[i];
    }



    for(int i = 1; i <= N; i++){
        if(max < a[i] && a[i]!=max) max += 1;
    }
    
    cout<<max;
}