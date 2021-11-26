#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> A;
    vector<int> copyA;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        A.push_back(value);
        copyA.push_back(value);
    }

    sort(copyA.begin(), copyA.end());

    vector<pair<int, int> > B;

    for(int i = 0; i < copyA.size(); i++) {
        int value = copyA[i];
        B.push_back(make_pair(value, i));
    }

    vector<int> P(n+1, 0);

    for(int i = 0; i < B.size(); i++) {
        int value = B[i].first;
        int index = B[i].second;

        P[index] = value;
    }

    for(int i = 0; i < A.size(); i++) {
        int value = A[i];
        
    }
}