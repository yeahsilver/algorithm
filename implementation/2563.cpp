#include <iostream>

using namespace std;

#define MAX 101

int main(void) {
    int testCase;
    cin >> testCase;
    
    int paper[MAX][MAX] = {0, };
    int area = 0;

    for(int i = 0; i < testCase; i++) {
        int x, y;
        cin >> x >> y;

        for(int j = 1; j <= 10; j++) {
           for(int k = 1; k <= 10; k++) {
                paper[x+j][y+k] = 1;
           }
        }
    }

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(paper[i][j]) {
                area++;
            }
        }
    }

    cout << area << '\n';
}