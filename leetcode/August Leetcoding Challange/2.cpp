#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
        
    // for(int i = 0 ; i <nums.size(); i++) {
    //     for(int j = i+1; j < nums.size(); j++) {
    //         if(i == j) continue;
            
    //         if(nums[i]+nums[j] == target) {
    //             result.push_back(i);
    //             result.push_back(j);
                
    //             break;
    //         }
    //     }
    // }

    // for(int i = 0; i < nums.size(); i++) {
    //     int value = target-nums[i];

    //     auto it = find(nums.begin()+i+1, nums.end(), value);

    //     if(it == nums.end()) {
    //         continue;

    //     } else {
    //         result.push_back(i);
    //         result.push_back(it-nums.begin());
    //         break;
    //     }
    // }

    unordered_map<int, int> hash_table;
    
    for(int i = 0; i < nums.size(); i++) {
        int find = target-nums[i];

        if(hash_table.find(find) != hash_table.end()) {
            result.push_back(hash_table[find]);
            result.push_back(i);

            return result;
        }

        hash_table[nums[i]] = i;
    }
    
    return result;
}

int main(void) {
    vector<int> nums;
    // nums.push_back(2);
    // nums.push_back(7);
    // nums.push_back(11);
    // nums.push_back(15);

    // int target = 9;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;

    vector<int> result = twoSum(nums, target);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}