#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<pair<int, int> > v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < N; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

}