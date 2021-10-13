#include <iostream>

using namespace std;

bool check(int num) {
    if(num < 100) {
        return true;
    }

    int one = num%10;
    int ten = (num%100)/10; 
    int hundred = num/100;

    if(ten-one == hundred-ten) {
        return true;
    }
    
    return false;
}

int main(void) {
    int n;
    cin >> n;

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(check(i)) {
            count++;
        }
    }

    cout << count << '\n';
}