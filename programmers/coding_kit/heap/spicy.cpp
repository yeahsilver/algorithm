#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > need_check(scoville.begin(), scoville.end());

    while(need_check.top() < K && need_check.size() > 1) {

        int first = need_check.top();
        need_check.pop();

        int second = need_check.top();
        need_check.pop();

        int mixed = first + (second*2);
        need_check.push(mixed);

        answer++;
    }

    if(need_check.top() < K) {
        return -1;
    }

    return answer;
}

int main(void) {
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    int K=7;

    cout << solution(scoville, K);
}