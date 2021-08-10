#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int start = 0;
        int end = s.size();

        while(s.size()!= 0) {
            // 1. 첫번쨰 글자와 마지막 글자 비교 
            // 같으면 뒤칸 -1
            // 있으면 앞 +1 앞 -1
            // start == end 같을 때 까지
        }
        
    }
};

int main(void) {
    Solution solution;

    solution.minCut("madamaabb");
}