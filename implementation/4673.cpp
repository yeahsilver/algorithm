#include <iostream>
#include <string>

using namespace std;

#define MAX 10000

int d(int n) {
    if(n < 10) {
        return n+n;
    } else if (n < 100) {
        return n + (n/10) + (n%10);
    } else if (n < 1000) {
        return n + (n/100) + (n%100/10) + (n%10);
    } else if (n < 10000) {
        return n + (n/1000) + (n%1000/100) + (n%100/10) + (n%10);
    }

    return 0;
}

int main(void) {
    bool isVisited[MAX+1] = {false, };

    for(int i = 0; i < MAX; i++) {

        int sum = 0;
        if(d(i) < MAX) {
            isVisited[d(i)] = true;
        }
    }
    
    for(int i = 0; i < MAX; i++) {
        if(!isVisited[i]) cout << i << '\n';
    }
}