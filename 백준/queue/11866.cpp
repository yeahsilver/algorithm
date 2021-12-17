#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    queue<int> q;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    int cnt = 1;
    int mul = 1;
    cout << '<';
    while(1) {
        if(q.empty()) {
            cout << '>';
            break;
        }

        if(cnt == K*mul) {
            int front = q.front();
            q.pop();
            cout << front;

            if(!q.empty()) {
                cout << ", ";
            }
            mul++;
            
        } else {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        cnt++;
    }
}