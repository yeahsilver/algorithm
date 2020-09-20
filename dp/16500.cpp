#include <iostream>
#include <string>

using namespace std;

int main(void){
    int num;
    int dp[101];
    string A[101];
    string S;

    cin >> S;
    cin >> num;
    
    for(int i = 0; i < num; i++){
        cin >> A[i];
    }
    
    dp[S.length()] = 1;

    for(int cur = S.length()-1; cur >= 0; cur--){
        for(int j = 0; j < num; j++){
            if(S.find(A[j], cur) == cur && dp[cur + A[j].length()] == 1){
                dp[cur] = 1;
                break;
            } else {
                dp[cur] = 0;
            }
        }
    }
    cout << dp[0] << '\n';
}