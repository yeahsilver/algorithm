#include <iostream>
using namespace std;


int main(void) {
    int a[101];
    int dp[10001] = {0, };

    int num, value;
    cin >> num >> value;

    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }    

    dp[0] = 1;

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= value; j++) {
            if(j >= a[i]) {
                dp[j] += dp[j-a[i]];
            }
        }   
    }

   cout << dp[value] << '\n';
}