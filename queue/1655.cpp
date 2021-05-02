/*
    priority_queue를 사용하여 중간값을 구하기
    1. maxHeap의 사이즈가 minHeap과 같거나 커야한다
    2. minHeap의 값은 최대 힙보다 항상 큰 값이 들어가야한다. (중간 값을 구하기 위해서)
    3. heap에 값을 넣어준 뒤, maxHeap.top()의 값이 minHeap.top()보다 크다면 값을 바꾸어준다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define for(variable, start, end) for(int variable = start; variable <=end; variable++) 

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int n;
    cin >> n;

    for(i, 0, n-1) {
        int value;
        cin >> value;

        // maxHeap이 비어있다면 
        if(maxHeap.size()==0) {
            maxHeap.push(value);
        } else {
            
            // maxHeap이 minHeap보다 크면  => minHeap에 값 삽입
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(value);
            } else {
                maxHeap.push(value);
            }

            if(maxHeap.top() > minHeap.top()) {
                int maxHeapTop = maxHeap.top();
                int minHeapTop = minHeap.top();

                maxHeap.pop();
                minHeap.pop();

                maxHeap.push(minHeapTop);
                minHeap.push(maxHeapTop);
            }
        }
        cout << maxHeap.top()<<'\n';
    }
}