#include <iostream>

using namespace std;


int main(void){
    bool dp[101][1001] = {false, };

    int N, S, M;
    int result = -1;
    int list[101] = {0,};
    
    cin >> N >> S >> M;
    
    for(int i = 0; i < N; i++){
        cin >> list[i];
    }

    dp[0][S] = true;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(!dp[i-1][j]) continue;
            if(j - list[i-1] >= 0) dp[i][j - list[i-1]] = true;
            if(j + list[i-1] <= M) dp[i][j + list[i-1]] = true;
        }
    }

    for(int i = 0; i <= M; i++){
        if(dp[N][i] == true){
           result = i;
        }
    }
     cout << result << '\n';
}   