#include <iostream>
using namespace std;

int main(void){
    int N;
    int a[1001] = {};
    int dp1[1001] = {};
    int dp2[1001] = {};
    int ans = 0;

    cin>>N;

    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }

    for(int i = 1; i <= N;i++){
            dp1[i] = 1;
            for(int j = 1; j <= i;j++){
                if(a[i] > a[j] && dp1[i] < dp1[j]+1)
                    dp1[i] = dp1[j]+1;
            }
        }

     for(int i = N; i >= 1;i--){
            dp2[i] = 1;
            for(int j = N; j >= i;j--){
                if(a[i] > a[j] && dp2[i] < dp2[j]+1)
                    dp2[i] = dp2[j]+1;
            }
        }

     for(int i = 0;i <= N; i++){
            if(ans <dp1[i]+dp2[i]-1) ans = dp1[i]+dp2[i]-1;
        }

    cout<<ans;

}