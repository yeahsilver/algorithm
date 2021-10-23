#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<int> blocks;
    for(int i = 0; i < W; i++) {
        int value;
        cin >> value;
        blocks.push_back(value);
    }

    int answer = 0;
    for(int i = 0; i < W; i++) {
        int left = 0;
        int right = 0;

        // 왼쪽에서 가장 긴 블록의 길이 구하기
        for(int j = 0; j < i; j++) {
            left = max(left, blocks[j]);
        }

        // 오른쪽에서 가장 긴 블록의 길이 구하기
        for(int j = W-1; j > i; j--) {
            right = max(right, blocks[j]);
        }
        
        answer += max(0, min(left, right) - blocks[i]);
    }
    cout << answer << '\n';
}