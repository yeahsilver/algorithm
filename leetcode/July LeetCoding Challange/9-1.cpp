#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    v.push_back(-__INT_MAX__);

    for(int i = 0; i < nums.size(); i++) {
        if(v.back() < nums[i]) {
            v.push_back(nums[i]);

        } else {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            *it = nums[i];
        }
    }

    return v.size()-1;
}

int main(void) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(7);

    // nums.push_back(7);
    // nums.push_back(7);
    // nums.push_back(7);
    // nums.push_back(7);


    cout << lengthOfLIS(nums) << '\n';
}