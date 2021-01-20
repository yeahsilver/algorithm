#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, value;
    int cnt = 0;
    cin >> num >> value;

    int* coin = new int[num];

    for(int i = 0; i < num; i++){
        cin >> coin[i];
    }

    sort(coin, coin+num, greater<int>());

    for(int i = 0; i < num; i++){
        while(value-coin[i] >= 0){
            value-=coin[i];
            cnt++;
        }
    }

    cout << cnt << '\n';

}