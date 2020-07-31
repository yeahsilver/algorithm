#include <iostream>

using namespace std;

int num, row, column, cnt;

void find_quadrant(int num, int x, int y){
    if(num == 2){
        if(x == row && y == column){
            cout << cnt <<'\n';
            return;
        }
        cnt++;
        if(x == row && y + 1 == column){
            cout<< cnt <<'\n';
            return;
        }
        cnt++;
        if(x + 1 == row && y == column){
            cout << cnt << '\n';
            return;
        }
        cnt++;
        if(x + 1 == row && y + 1 == column){
            cout << cnt << '\n';
            return;
        }
        cnt++;
        return;
    }
    find_quadrant(num / 2,  x, y);
    find_quadrant(num / 2, x, y + num / 2);
    find_quadrant(num / 2,  x + num / 2, y);
    find_quadrant(num / 2,  x + num / 2, y + num / 2);
}
int main(void){
    cin >> num >> row >> column;

    find_quadrant( 1 << num, 0, 0);
}