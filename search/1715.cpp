#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    int N;
    int result = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> N;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        pq.push(input);
    }

    for(int i = 0; i < N-1; i++){
        int first, second;
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();

        pq.push(first + second);
        result += first + second;
    }

    cout << result;
}