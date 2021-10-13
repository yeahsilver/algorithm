#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(int a, int b){
    return a > b;
}

int main(void){
    int num, sum, ans = 0;
    cin >> num >> sum;

    vector<int> v(num);

    for(int i = 0; i < num; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < num; i++){
        while(sum-v[i] >= 0){
            ans++;
            sum-=v[i];
        }
    }
    cout << ans << '\n';
}