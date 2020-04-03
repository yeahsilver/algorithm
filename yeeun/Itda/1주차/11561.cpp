// 시간초과
#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        long long N;
        long long max = 0;
        cin>> N;
        if(N==1 || N ==2) {
            cout<<"1"<<"\n";
            continue;
        }
        for(long long i = 3; i <= N; i++){
            long long x = 1+(i*(i+1))/2;
            if(x <= (int) N){
                max = i;
            } else {
                    continue;
                }
            }   
            cout<<max;

        }
    }