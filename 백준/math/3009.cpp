#include <iostream>

using namespace std;

#define MAX 1001

int main(void) {
    int xArray[MAX] = {0, };
    int yArray[MAX] = {0, };

    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        xArray[x]++;
        yArray[y]++;
    }

    int resultX = 0, resultY = 0;

    for(int i = 0; i < MAX; i++) {
        if(resultX != 0 && resultY != 0) {
            break;
        }

        if(xArray[i] == 1) {
            resultX = i;
        }

        if(yArray[i] == 1) {
            resultY = i;
        }
    }

    cout << resultX << ' ' << resultY << '\n';
}