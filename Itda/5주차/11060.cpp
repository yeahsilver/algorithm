#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[1001] = {0,};
    int N;

    cin >> N;

    dp[1] = 1; // 뛰어야하기 때문에 초기값을 1로 지정. 

    for(int i = 1; i <= N; i++){
        int M;
        cin >> M;

        for(int j = 1; i <= M; j++){
            if(dp[i+j] == 0 || dp[i+j] > dp[i]+1){ 
                dp[i+j] = dp[i] + 1;
                
            }
        }
    }

    if(dp[N] == 0)
        cout<<-1<<'\n';
    else 
        cout << dp[N]-1 <<'\n';
        

    // for(int i = 1; i <=  N; i++){
    //     if(a[i]>N) cout << "-1" <<'\n';
    // }


    for(int i = 2; i <= N; i++){

    }
}