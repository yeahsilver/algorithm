#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    deque<int> dq;

    for(int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    vector<int> numbers;
    
    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;

        numbers.push_back(num);
    }

    int index = 0;
    int count = 0;

    while(1) {
        if(index >= numbers.size()) {
            break;
        }    

        int target = numbers[index];

        if(target == dq.front()) {
            dq.pop_front();
            index++;

        } else if(target > dq.front()) {
            int front = dq.front();
            dq.pop_front();
            dq.push_back(front);

            count++;

        } else if(target < dq.front()) {
            int back = dq.back();
            dq.pop_back();
            dq.push_front(back);

            count++;
        }
    }

    cout << count << '\n';

}