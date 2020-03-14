#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(void){
    int N;
    cin>>N;
    vector<pair<int, string> > v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i].first>>v[i].second;
    }
    
    stable_sort(v.begin(),v.end(),cmp);

    for(int i = 0; i < N; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    
<<<<<<< HEAD
}
=======
}
>>>>>>> 6d79912af21ea0707c8b270ca261cecec55a0f21
