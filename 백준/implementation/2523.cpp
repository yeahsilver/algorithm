#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    bool isOver = false;

    int count = 0;
    for(int i = 1; i <= n*2; i++) {
        if(isOver) {
            count--;
        } else {
            count++;
        }

        for(int j = 1; j <= count; j++) {
            cout << "*";
        }

        if(i != n*2) {
            cout << '\n';
        }
        
        if(count == n) {
            isOver = true;
        }
    }
}