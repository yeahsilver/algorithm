#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int num, players, present, round;
    cin >> num >> players >> present >> round;

    vector<int> values[10];

    for(int i = 0; i < players; i++) {
        for(int j = 0; j < round; j++) {
            int value;
            cin >> value;
            values[i].push_back(value);
        }
    }

    queue<int> roulette;
    
    roulette.push(1);

    for(int i = num; i > 1; i--) {
        roulette.push(i);
    }

    for(int i = 0; i < round; i++) {
        for(int j = 0; j < players; j++) {

            int rotate = values[j][i];

            // cout <<  "rotate: " << rotate << '\n';

            for(int k = 0; k < rotate; k++) {
                int currentRoulette = roulette.front();

                roulette.pop();
                roulette.push(currentRoulette);
            }

            // cout << "After Rotate: " << roulette.front() << '\n';

            if(roulette.front() == present) {
                cout << j+1 << ' ' << i+1;
                break;
            }
        }
    }    
}