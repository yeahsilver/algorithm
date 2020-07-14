// 왜 틀린지 모르겠어요..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    cin .tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, total = 0, cnt = 0, sum = 0, num, size;
    cin >> N;   
    vector<int> v(N);
    for(int i =0; i < N*N; i++){
        cin>>v[i];
        total+=v[i];
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < N*N; i++){
        auto low = lower_bound(v.begin(),v.end(),i);
        auto high = upper_bound(v.begin(),v.end(),i);
        num = high-low;
        cout<<"num: "<<num<<'\n';
        size = N * N;
        size-=num;
        cout<<"size: "<<size<<'\n';
        sum += size;
        cout<<"sum: "<<sum<<'\n';
        if(sum < (total/2)){
            cnt++;
        } else {
            break;
        }
    }
    cout<<cnt;

}