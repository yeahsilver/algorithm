#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, X;
    cin >> N >> X;

    vector<int> visiters;
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        visiters.push_back(value);
    }

    int max = 0;
    int days = 0;

    int left = 0;
    int right = 0;

    int sum = visiters[left];

    while(1) {
        
        if(right >= visiters.size()) {
            break;
        }

        int diff = right - left + 1;

        if(diff == X) {
            if(max < sum) {
                max = sum;
                days = 1;

            } else if (max == sum) {
                days++;
            }

            sum -= visiters[left];
            left++;

            right++;
            
            if(right < visiters.size()) {
                sum += visiters[right];
            }

        } else if (diff < X) {

            right++;

            if(right < visiters.size()) {
                sum += visiters[right];
            }

        } else if (diff > X) {
            sum -= visiters[left];
            left++;
        }
    }

    if(max == 0) {
        cout << "SAD\n"; 
    } else {
        cout << max << '\n' << days << '\n';
    }
}