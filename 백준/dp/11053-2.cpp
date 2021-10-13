#include <iostream>

using namespace std;

int main(void){
    int a[1001] = {0,};
    int dp[1001] = {0,};

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] > a[j] && dp[i] < dp[j] +1 ){
                dp[i] = dp[j]+1;
            }
        }
    }

    int MAX = 0;

    for(int i = 0; i < N; i++){
        MAX = max(MAX, dp[i]);
    }

    cout << MAX << '\n';
}