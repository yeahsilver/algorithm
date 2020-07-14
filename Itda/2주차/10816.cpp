#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i <N; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    cin >> M;
    for(int i = 0; i <M; i++){
        int n;
        cin>> n;
        auto low = lower_bound(v.begin(),v.end(), n);
        auto high = upper_bound(v.begin(), v.end(), n);
        cout<<high-low<<" ";
    }
}