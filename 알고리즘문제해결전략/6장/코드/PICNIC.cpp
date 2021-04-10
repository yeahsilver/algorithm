#include <iostream>
#include <cstring>

using namespace std;

#define MAX 11
#define for(i, start, n) for(int i = start; i < n; i++)

int student, pair_number;

bool areFriends[MAX][MAX];
bool isChecked[MAX] = {0, };

int countingPairs(){
    int count = 0;
    int firstFree = -1;

    // 체크하지 않은 친구의 번호를 for문을 통해 돌려 가지고오기
    for(i, 0, student) {
        if(!isChecked[i]) {
            firstFree = i;
            break;
        }
    }

    // 친구 모두르 체크했다면 1을 리턴함으로써 1가지 경우의 수가 만들어졌음을 알림
    if(firstFree == -1) {
        return 1;
    }

    // 다음 친구부터 체크 했는지 안했는지 확인 후에 체크하지 않았으면 해당 친구를 짝으로 타깃 설정 후 다른 짝을 찾음.
    for(i, firstFree+1, student) {
        if(!isChecked[i] && areFriends[firstFree][i]) {
            isChecked[firstFree] = true;
            isChecked[i] = true;

            count += countingPairs();

            // 1가지 경우의 수를 모두 찾은 뒤 실행되는 함수임.
            // isChecked에 대한 값을 false로 만들어 다음 경우의 수를 체크할 수 있게 만듦
            isChecked[firstFree] = false;
            isChecked[i] = false;
        }
    }

    return count;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    while(test_case--) {
        memset(areFriends, false, sizeof(areFriends));
        memset(isChecked, false, sizeof(isChecked));

        cin >> student >> pair_number;

        for(i, 0, pair_number) {
            int pair_first, pair_second;
            cin >> pair_first >> pair_second;

            areFriends[pair_first][pair_second] = true;
            areFriends[pair_second][pair_first] = true;
        }

        int result = countingPairs();

        cout << result << '\n';
    }

}