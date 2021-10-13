#include <iostream>

using namespace std;

int main(void) {
    bool isBottom = false;
    bool isRight = false;

    int X;
    cin >> X;

    int x = 1;
    int y = 1;

    X--;
   
    while(X--) {
        if(x == 1) {
            if(isRight) {
                isBottom = false;
                x++;
                y--;
            } else {
                isRight = true;
                y++;
            }
        } else if(y == 1) {
            if(isBottom) {
                isRight = false;
                x--;
                y++;
            } else {
                isBottom = true;
                x++;
            }
        } else {
            if(isRight) {
                x++;
                y--;
                
            } else if(isBottom) {
                x--;
                y++;
            }
        }
    }

    cout << x << '/' << y << '\n';
}