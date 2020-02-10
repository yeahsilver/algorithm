#include <iostream>
using namespace std;

int main(){
  int N,sum=0;
  cin>>N;
  char num[N];
  for(int i=0;i<N;i++){
    cin>>num[i];
    sum+=(num[i]-'0');
  }
  cout<<sum;
  return 0;
}
