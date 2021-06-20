#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;
    queue<int> trucks;
    queue<pair<int, int> > bridge_truck;

    while(true) {
        answer++;

        if(trucks.size() == bridge_length) {
            sum-=trucks.front();
            trucks.pop();
        }
        if(sum + truck_weights[idx] <= weight) {
            if(idx == truck_weights.size()-1) {
                answer += bridge_length;
                break;
            }

            int truck_weight = truck_weights[idx];
            trucks.push(truck_weight);
            sum+= truck_weight;

            idx++;

        } else {
            trucks.push(0);
        }
    }
    
    return answer;
}

int main(void) {
    int bridge_length = 2;
    int weight = 10;

    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);

    cout << solution(bridge_length, weight, truck_weights);
}