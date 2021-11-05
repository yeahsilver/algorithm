#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case) {
        int N;
        cin >> N;

        int mid;
        vector<int> answer;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int> > min_pq;

        cout << (N+1)/2 << '\n';

        for(int i = 1; i <= N; i++) {
            int value;
            cin >> value;

            int min_size = min_pq.size();
            int max_size = max_pq.size();

            if(min_size == max_size) {
                max_pq.push(value);

            } else {
                min_pq.push(value);
            }
        }
    }
}