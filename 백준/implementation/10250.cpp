#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int H, W, N;
        cin >> H >> W >> N;

        int y;
        int x;

        if(N%H == 0) {
            y = H;
            x = N/H;
        } else {
            y = N%H;
            x = N/H+1;
        }

        if(N == H*W) {
            y = H;
            x = W;
        }
        
        if(x < 10) {
            y*=10;
        }

        cout << y << x << '\n';
    }
}