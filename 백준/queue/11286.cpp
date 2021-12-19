#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if(num > 0) {
            pq.push(make_pair(num, 1));
        } else if (num < 0) {
            pq.push(make_pair(num*-1, 0));
        }
        
        if(num == 0) {
            if(!pq.empty()) {
                int first = pq.top().first;
                int second = pq.top().second;

                pq.pop();
                
                if(second) {
                    cout << first << '\n';
                } else {
                    cout << first * -1 << '\n';
                }

            } else {
                cout << 0 << '\n';
            }
            
        }
    }
}