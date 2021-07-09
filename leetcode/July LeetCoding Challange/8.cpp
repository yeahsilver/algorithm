#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int dp[n+1][m+1];

    int maxValue = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums1[i] == nums2[j]) {
                if(i > 0 && j > 0) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxValue = max(maxValue, dp[i][j]);
                } else {
                    dp[i][j] = 1;
                }
            }  else {
                dp[i][j] = 0;
            }
        }
    }

    return maxValue;
} 

int main(void) {
    vector<int> nums1, nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(2);
    nums1.push_back(1);

    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(1);
    nums2.push_back(4);
    nums2.push_back(7);

    cout << findLength(nums1, nums2) << '\n';
}
