#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unsigned long long T;
    cin >> T;
    while(T--){
        unsigned long long  N;
        cin >> N;
        unsigned long long low = 0, mid = 0, high = N;
        while (low <= high){
            mid = (low+high)/2;
            if(mid*(mid+1LL) <= N*2){
                low = mid+1LL;
            } else {
                high = mid-1LL;
                mid--;
            }
        }
        cout<<mid<<'\n';
    }
}