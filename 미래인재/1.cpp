#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int px, py;
    int qx, qy;

    cin >> px >> py;
    cin >> qx >> qy;

    int fx, fy;

    fx = abs(qx-px);
    fy = abs(qy-py);

    if(fx == fy){
        if(fx == 0 && fy == 0){
            cout << "DOT" << '\n';
        } else {
             cout << "SQUARE" << '\n';
        }
    }else {
        if(fx == 0 || fy == 0){
            cout << "SEGMENT" << '\n';
        } else {
            cout << "RECTANGLE" << '\n';
        }
    }
    return 0;
}