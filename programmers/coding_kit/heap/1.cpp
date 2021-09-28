#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > q(scoville.begin(), scoville.end());
    
    while(1) {  
        if(q.top() >= k || q.size() < 2) {
            break;
        }

        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        
        q.push(first + (second*2));
        answer++;
    }

    if(q.top() < k) {
        return -1;
    }

    return answer;
}

int main(void) {
    vector<int> scoville;

    // scoville.push_back(2);
    // scoville.push_back(1);
    // scoville.push_back(9);
    // scoville.push_back(3);
    // scoville.push_back(10);
    // scoville.push_back(12);

    scoville.push_back(1);
    scoville.push_back(1);
    scoville.push_back(1);
    scoville.push_back(1);

    int k = 100000;

    cout << solution(scoville, k) << '\n';
}