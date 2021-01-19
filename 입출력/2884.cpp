#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H, M;
    cin >> H >> M;

    M-=45;

    if(M < 0){
        H-=1;
        M = M+60;
        if(H < 0){
            H = 24+H;
        }
    }

    cout << H << ' ' << M << '\n';
}