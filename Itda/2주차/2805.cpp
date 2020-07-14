#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long N, M, MAX = 0, ans = 0;
    cin>>N>>M;
    vector<long long> v(N);
    for(long long i = 0; i < N; i++){
        cin>>v[i];
        MAX = max(MAX,v[i]);
    }

    long long low  = 0, high = MAX, mid, total = 0;
    while(low<=high){
        mid = (low + high)/2;
        for(long long i = 0; i <N;i++){
            if(v[i] >= mid){
                total += v[i] - mid;
            }
        }
        if(total < M){
            high = mid - 1;
        } else { 
            ans = mid;
            low = mid + 1;
        }

        total = 0;
    }
    cout<<ans;
}