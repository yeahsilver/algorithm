#include <iostream>
using namespace std;

int main(void){
    int M, N;
    int cnt = 0;
    cin >> M >> N;

    for(int i = M; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0) cnt++;
        }
        if(cnt == 2) cout<<i<<'\n';
        cnt = 0;
    }
}
