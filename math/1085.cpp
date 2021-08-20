#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    
    int minValue = __INT_MAX__;
    
    if(x < w-x || x < h-y) {
        if(minValue > x) {
            minValue = x;
        }
    }

    if(y < w-x || y < h-y) {
        if(minValue > y) {
            minValue = y;
        }
    }

    minValue = min((w-x), min((h-y), minValue));

    cout << minValue << '\n';
}