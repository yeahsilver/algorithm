#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int city;
    cin >> city;

    long long* road = new long long[city];
    long long* cost = new long long[city];

    for (int i = 0; i < city-1; i++) {
        cin >> road[i];
    }

    for (int i = 0; i < city; i++) {
        cin >> cost[i];
    }

    long long minValue = cost[0];
    long long answer = 0;

    for (int i = 0; i < city-1; i++) {
        if(minValue > cost[i]) {
            minValue = cost[i];
        }
        answer += road[i] * minValue;
    }

    cout << answer << '\n';
}