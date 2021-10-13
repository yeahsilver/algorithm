#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > q;

    for(auto& i: scoville) {
        q.push(i);
    }

    while(1) {
        int min1 = q.top();
        q.pop();

        if(min1 >= k) {
            break;

        } else if(q.empty()) {
            answer = -1;
            break;
        }

        int min2 = q.top();
        q.pop();

        q.push(min1 + (min2*2));
        answer++;
    }

    return answer;
}

int main(void) {
    vector<int> scoville;

    scoville.push_back(2);
    scoville.push_back(1);
    scoville.push_back(9);
    scoville.push_back(3);
    scoville.push_back(10);
    scoville.push_back(12);

    // scoville.push_back(1);
    // scoville.push_back(1);
    // scoville.push_back(1);
    // scoville.push_back(1);

    int k = 7;

    cout << solution(scoville, k) << '\n';
}