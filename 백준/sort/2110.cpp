#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int N, M;

void binary_search(vector<int> distance) {
    int start = 0;
    int end = distance.length();
    int mid;

    while(start <= end) {
        mid = (start + end) / 2;
        int value = distance[0];
        cnt++;

        for(int i = 0; i < N; i++) {

        }
    }    


}

int main(void) {
    cin >> N >> M;

    vector<int> distance;
    
    for(int i = 0; i < N; i++) {
        int dist;
        cin >> dist;
        distance.push_back(distance);
    }

    sort(distance.begin(), distance.end());

    binary_search(distance);
}

   