#include <iostream>
using namespace std;

int main(){
  int T,A,B,i=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&A,&B);
    printf("Case #%d: %d\n",i++,A+B);
  }
  return 0;
}
