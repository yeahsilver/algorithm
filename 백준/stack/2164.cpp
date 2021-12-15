#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    queue<int> q;

    for(int i = 1; i <= num; i++) {
        q.push(i);
    }

    while(1) {
        if(q.size() <= 1) {
            cout << q.front() << '\n';
            break;
        }

        q.pop();
        
        int front = q.front();
        q.pop();
        
        q.push(front);
    }
}