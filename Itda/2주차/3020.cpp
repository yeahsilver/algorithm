#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,H, total = 0, min = __INT_MAX__, cnt = 1;
    cin>>N>>H;

    vector<int> v1(N/2), v2(N/2); //v1은 위, v2는 아래

    for(int i = 0; i <N/2; i++){
        cin>>v1[i];
        cin>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(int i = 1; i <=H; i++){
        int low = v1.size() - (lower_bound(v1.begin(),v1.end(),i)-v1.begin());
        int high = v2.size() - (upper_bound(v2.begin(),v2.end(),H-i)-v2.begin());
        total = low + high;
        if(total == min){
            cnt++;
        } else if(total < min){
            min = total;
            cnt = 1;
        }
    }
    cout<<min<<" "<<cnt;
}