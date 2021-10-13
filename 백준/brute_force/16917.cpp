#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int sauce_price, fried_price, half_price, sauce_num, fried_num;
    int answer = __INT_MAX__;
    
    cin >> sauce_price >> fried_price  >> half_price >> sauce_num >> fried_num ;

    for(int i = 0; i <= 100000; i++) {
        int half = 2 * half_price*i;
        int sauce = max(0, (sauce_num-i)*sauce_price);
        int fried = max(0, (fried_num-i)*fried_price);

        answer = min(answer, sauce + fried + half);
    }

    cout << answer << '\n';
}