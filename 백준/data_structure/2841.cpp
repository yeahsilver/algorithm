#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int N, P;
    cin >> N >> P;

    stack<int> numbers[7];

    int answer = 0;

    for(int i = 0; i < N; i++) {
        int melody, fret;
        cin >> melody >> fret;

        if(numbers[melody].empty()) {
            numbers[melody].push(fret);
            answer++;

        } else {
            int value = numbers[melody].top();
            
            if(value == fret) {
                continue;
            } 
            
            if(value > fret) {
                while(1) {
                    if(numbers[melody].empty() || numbers[melody].top() < fret) {
                        numbers[melody].push(fret);
                        answer++;
                        break;
                    }

                    if(numbers[melody].top() == fret) {
                        break;
                    }

                    numbers[melody].pop();
                    answer++;
                }
            } else {
                numbers[melody].push(fret);
                answer++;
            }
        }
    }
    cout << answer << '\n';
}