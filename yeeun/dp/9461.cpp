#include <iostream>
#include <algorithm>
using namespace std;

long long arr[101] = {1,1,1,2,2};

long long solve(long long n){
   if(n <= 4) return arr[n];
   if(arr[n] > 0) return arr[n];
   return arr[n] = solve(n - 1) + solve(n - 5);
}
int main(){
   int t, n;
   cin >> t;

   while(t--){
      cin >> n;
      n--;
      cout << solve(n) << '\n';
   }
}