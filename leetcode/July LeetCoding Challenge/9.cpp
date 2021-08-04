#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int* dp = new int[nums.size()];

    for(int i = 0; i <  nums.size(); i++) {
        dp[i] = 1;
    }

    int maxValue = 1;

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
                maxValue = max(dp[i], maxValue);
            }
        }
    }

    return maxValue;
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

    cout << lengthOfLIS(nums) << '\n';
}