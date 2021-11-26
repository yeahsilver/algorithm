#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> A;
    vector<pair<int, int> > copyA;


    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        A.push_back(value);
        copyA.push_back(make_pair(value, i));
    }

    sort(copyA.begin(), copyA.end());

    vector<pair<int, int> > B;
    
    for(int i = 0; i < A.size(); i++) {
        int first = copyA[i].first;
        int second = copyA[i].second;

        B.push_back(make_pair(first, second));
    }

    vector<pair<pair<int, int> , int> > answer;

    for(int i = 0; i < A.size(); i++) {
        int index = i;
        int value = B[i].first;
        int pIndex = B[i].second;

        answer.push_back(make_pair(make_pair(pIndex, value), index));
    }

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++) {
        int index = answer[i].second;
        cout << index << ' ';
    }
}