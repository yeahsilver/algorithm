#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> my_card;
    
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;

        my_card.push_back(value);
    }

    sort(my_card.begin(), my_card.end());

    int M;
    cin >> M;

    vector<int> card;

    for(int i = 0; i < M; i++) {
        int value;
        cin >> value;

        card.push_back(value);
    }

    for(int i = 0; i < M; i++) {
       cout << upper_bound(my_card.begin(), my_card.end(), card[i]) - lower_bound(my_card.begin(), my_card.end(), card[i]) << ' ';
    }
}