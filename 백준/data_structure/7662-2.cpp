#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;

        for(int i = 0; i < num; i++) {
            char type;
            int number;

            cin >> type >> number;

            if(type == 'I') {
                minHeap.push(number);
                maxHeap.push(number);

            } else if(type == 'D') {
                if(number == 1) {
                    if(!maxHeap.empty()) {
                        int max = maxHeap.top();
                        maxHeap.pop();

                        vector<int> numbers;
                        while(!minHeap.empty()) {
                            int value = minHeap.top();
                            numbers.push_back(value);
                            minHeap.pop();
                        }

                        for(int i = 0; i < numbers.size()-1; i++) {
                            minHeap.push(numbers[i]);
                        }
                    }
                } else if(number == -1) {
                    if(!minHeap.empty()) {
                        int min = minHeap.top();
                        minHeap.pop();

                        vector<int> numbers;
                        while(!maxHeap.empty()) {
                            int value = maxHeap.top();
                            numbers.push_back(value);
                            maxHeap.pop();
                        }

                        for(int i = 0; i < numbers.size()-1; i++) {
                            maxHeap.push(numbers[i]);
                        }
                    }
                }
            }
        }

        if(minHeap.empty() && maxHeap.empty()) {
            cout << "EMPTY\n";
        } else {
            int max = maxHeap.top();
            int min = minHeap.top();

            cout << max << ' ' << min << '\n';
        }
    }
}