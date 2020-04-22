#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long X, Y;
    long long low = 1;
    long long high = 1000000001;
    long long ans = -1;
    long long mid = 0;

    cin >> X >> Y;

    long long Z = (100*Y)/X;

    if(Z >= 99){
        cout<<"-1";
        return 0;
    } else {
        while(low<=high){
            mid = (low+high)/2;
            long long newZ = (100*(Y+mid))/(X+mid);

            if(Z < newZ){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    cout<<low;
}