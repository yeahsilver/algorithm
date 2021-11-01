#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(void) {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int> > chicken;
    vector<pair<int, int> > house;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int value;
            cin >> value;

            if(value == 1) {
                house.push_back(make_pair(i, j));

            } if(value == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> temp;
    for(int j = 0; j < M; j++) {
        temp.push_back(1);
    }

    for(int j = 0; j < chicken.size() - M; j++) {
        temp.push_back(0);
    }

    sort(temp.begin(), temp.end());
    int minValue = __INT_MAX__;

    do {

        vector<int> result(house.size(), __INT_MAX__);
        int sum = 0;

        for(int i = 0; i < temp.size(); i++) {
            
            if(temp[i] == 1) {
                int first = chicken[i].first;
                int second = chicken[i].second;

                for(int j = 0; j < house.size(); j++) {
                    int distance = abs(first - house[j].first) + abs(second - house[j].second);
                    result[j] = min(distance, result[j]);
                }
            }
        }

        for(int i = 0; i < result.size(); i++) {
            sum += result[i];
        }

        minValue = min(sum, minValue);

    } while(next_permutation(temp.begin(), temp.end()));

    cout << minValue << '\n';
}