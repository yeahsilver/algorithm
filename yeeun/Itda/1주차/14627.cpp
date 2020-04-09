#include <iostream>
#include <vector>
using namespace std;

long long sum=0, ans = 0;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long S, C, result = 0;
    cin >> S >> C;
    long long* L = new long long[S];
   
    for(long long i = 0; i < S; i++){
        cin>>L[i];
        sum+=L[i];
    }
    long long low = 1, high = 1000000000;

    while(low<=high){
        long long mid = (low+high)/2, cnt = 0;
        for( long long i = 0; i <S; i++){
            cnt+=L[i]/mid;
        } // 파의 길이에서 mid를 나누어줌으로써 파의 최대길이를  계산
            if(cnt < C){
                high = mid - 1;
            } else{
                if(ans < mid){ // 파의 길이는 최대값으로 구해야하기 때문에 mid가 ans를 비교
                    ans = mid;
                }
                low = mid + 1;
            }
        }
        result = sum-(ans*C);
        cout<<result;
        
}

