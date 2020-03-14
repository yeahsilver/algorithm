#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, n;
    int max = 0;
    vector<int> v;
    v.push_back(0);
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>n;
        if(n > v.back()){
            v.push_back(n);
            max++;
        } else {
            vector<int>::iterator iter = lower_bound(v.begin(),v.end(),n);
            *iter = n;
        }
    }
    cout<<max;
}