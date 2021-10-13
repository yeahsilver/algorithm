#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    while(1) {
        int a, b, c;
        vector<int> nums;
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0) {
            break;
        }

        nums.push_back(a);
        nums.push_back(b);
        nums.push_back(c);

        sort(nums.begin(), nums.end());

        int formula = pow(nums[0], 2) + pow(nums[1], 2);

        if(formula == pow(nums[2],2)) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }


    }
}