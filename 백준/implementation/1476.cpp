#include <iostream>

using namespace std;

int main(void) {
    int E, S, M;
    cin >> E >> S >> M;

    int i = 1;
    while(1) {
        int earth = (i-1)%15+1;
        int sun = (i-1)%28+1;
        int moon = (i-1)%19+1;

        if(earth == E && sun == S && moon == M) {
            cout << i << '\n';
            break;
        }
        i++;
    }
}