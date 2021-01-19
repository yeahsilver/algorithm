#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int index;
    int maxValue = 0;

    for(int i = 1; i <= 9; i++){
        int x;
        cin >> x;

        if(maxValue < x){
            maxValue = x;
            index = i;
        }
    }
    cout << maxValue << '\n';
    cout << index << '\n';
}