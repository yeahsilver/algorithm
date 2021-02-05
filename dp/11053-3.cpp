#include <iostream>
using namespace std;

#define MAX 1001

int main(void) {
    int a[MAX];
    int dp[MAX] = {0,};

    int num;
    cin >> num;

    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }

   for(int i = 1; i <= num; i++) {
       dp[i] = 1;
       for(int j = 1; j <= i; j++) {
           if(a[i] > a[j] && dp[i] < dp[j] +1 ) {
               dp[i] = dp[j]+1;
           } 
       }
   }
  
  int maxValue = 0;

  for(int i = 1; i <= num; i++) {
      if(maxValue < dp[i]) {
          maxValue = dp[i];
      }
  }

  cout << maxValue << '\n';
}