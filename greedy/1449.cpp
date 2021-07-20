#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, L;
    cin >> N >> L;

    vector<int> leaks;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        leaks.push_back(value);
    }

    if(L == 1) {
        cout << leaks.size() << '\n';
        return 0;
    }

    sort(leaks.begin(), leaks.end());

    L--;

    int answer = 0;
    int start = leaks.front();
    int startIdx = 0;

    int j = 0;

    bool isFinished = false;

    while(1) {

        int tape = start + L;
        int count = 0;
    

        // 탈출 조건 : 인덱스가 마지막 값을 가리킬 때 
        if(j >= leaks.size()-1) {
            if(!isFinished) {
                answer++;
            }
            break;
        }

        for(j = startIdx; j < leaks.size(); j++) {
            if(tape >= leaks[j]) {
                count++; // 해당 값이 테이프에 포함할 수 있다면

                if (leaks[j] == leaks.back()) { // 값이 테이프에 포함되는데 마지막 값이라면 미리 잘라주어야함.
                    isFinished = true;
                    break;
                }
            }

            else if(tape < leaks[j]) { // 해당 값이 테이프에 포함할 수 없다면
                startIdx = j;
                start = leaks[j];
                break;
            }
        }

        if(count > 0) {
            answer++;
        }

    }

    cout << answer << '\n';
}