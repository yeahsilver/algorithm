#include <iostream>
#include <algorithm>
#define MAX 1000002
using namespace std;

int main(void){
    int N;
    int cnt = 1;
    long long array[MAX];

    cin >> N;
    cin >> array[cnt];

    for(int i = 2; i <= N; i++){
        int num;
        cin >> num;
        if(num> array[cnt]){
            array[++cnt] = num;
        } else {
            auto iter = lower_bound(array+1, array+cnt, num);
            *iter = num;
        }
    }
    cout << cnt << '\n';
}