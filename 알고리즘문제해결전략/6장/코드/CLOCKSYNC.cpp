#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 99999
#define SWITCHES 10
#define CLOCKS 16
#define for(i, start, end) for(int i = start; i < end; i++)

char linked[SWITCHES][CLOCKS+1] = {
    "1110000000000000",
    "0001000101010000",
    "0000100000100011",
    "1000111100000000",
    "0000001110101000",
    "1010000000000011",
    "0010000000000011",
    "0000110100000011",
    "0111110000000000",
    "0001110001000100"
};

bool areAligned(vector<int> clocks) {
    for(i, 0, CLOCKS) {
        if(clocks[i] != 12) {
            return false;
        }
    }
    return true;
}

void push(vector<int> clocks, int swtch) {
    for(i, 0, CLOCKS) {
        if(linked[swtch][i] == '1') {
            // 3 -> 6 -> 9 -> 12로 돌아야하기에 3씩 더해줌
            clocks[i] += 3;

            if(clocks[i] == 15) {
                clocks[i] = 3;
            }
        }
    }
}

int solve(vector<int> clocks, int swtch) {
    // switch가 켜진 횟수가 SIWTCHS 만큼이면  clocks가 모두 12가 되었는지 확인해야함.
    if(swtch == SWITCHES) {
        return areAligned(clocks) ? 0 : INF;
    }

    int result = INF;

    // 12시 -> 3시 -> 6시 -> 9시 이동하는 횟수 = 4회
    for(i, 0, 4) {
        result = min(result, i + solve(clocks, swtch+1));

        push(clocks, swtch);
    }

    return result;
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int test_case;
   cin >> test_case;

   while(test_case--) {
        int result = 0;

        vector<int> clocks;

        for(i, 0, CLOCKS) {
            int value;
            cin >> value;

            clocks.push_back(value);
        }

        result = solve(clocks, 0);

        if (result == INF) {
            result = -1;
        }

        cout << result << '\n';
   }
}