#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        deque<int> dq;

        for(int i = 0; i < num; i++) {
            char type;
            int number;
            cin >> type >> number;

            if(type == 'I') {
                dq.push_back(number);
                
            } else if(type == 'D') {
                if(!dq.empty()) {
                    sort(dq.begin(), dq.end());
                    if(number == 1) {
                        dq.pop_back();
                    } else if(number == -1) {
                        dq.pop_front();
                    }
                }
            }
        }

        if(dq.empty()) {
            cout << "EMPTY\n";
        } else {
            int min = __INT_MAX__, max = 0;
            
            while(!dq.empty()) {
                int front = dq.front();

                if(min > front) {
                    min = front;
                }

                if(max < front) {
                    max = front;
                }

                dq.pop_front();
            }

            cout << max << ' ' << min << '\n';
        }
    }
}