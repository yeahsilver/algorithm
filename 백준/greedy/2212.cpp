#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;

    if(K >= N){
        cout << "0\n";
        return 0;
    }

    vector<int> sensorPosition(N);

    for(int i = 0; i < N; i++){
        cin >> sensorPosition[i];
    }

    sort(sensorPosition.begin(), sensorPosition.end());


    vector<int> distance(N-1);
    for(int i = 0; i < N-1; i++){
        distance[i] = sensorPosition[i+1] - sensorPosition[i];
    }

    sort(distance.begin(), distance.end(), greater<int>());

    for(int i = 0; i < K-1; i++){
        distance[i] = 0;
    }

    int result = 0;
    for(int i = 0; i < N-1; i++){
        result+= distance[i];
    }

    cout << result << '\n';
}