#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    if(N == 1) {
        cout << 1 << '\n';
        return 0;
    }


    int sum = 1;
    int count = 1;

    while(1) {
        if(sum >= N) {
            break;
        }

        sum += (6*count);
        count++;
    }

    cout << count << '\n';
}
