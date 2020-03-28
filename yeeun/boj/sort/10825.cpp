#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
pair<pair<string, int> ,pair<int, int> > v[100001];

bool cmp(pair<pair<string, int> ,pair<int, int> > a,pair<pair<string, int> ,pair<int, int> > b){
    if (a.first.second > b.first.second) return true;
    else if(a.first.second == b.first.second){
        if(a.second.first < b.second.first) return true;
        else if(a.second.first == b.second.first){
            if(a.second.second > b.second.second) return true;
            else if(a.second.second == b.second.second){
                if(a.first.first < b.first.first) return true;
            }
        }
    }
    return false;
}

int main(void){
    int N;
    cin>>N;

    
    for(int i = 0; i < N; i++){
        cin>>v[i].first.first>>v[i].first.second>>v[i].second.first>>v[i].second.second;
    }

    sort(v, v + N, cmp);   

    for(int i = 0; i< N; i++){
        cout<<v[i].first.first<<"\n";
    } 
<<<<<<< HEAD
}
=======
}
>>>>>>> 6d79912af21ea0707c8b270ca261cecec55a0f21
