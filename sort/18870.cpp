#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;


    vector<int> axis;
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        axis.push_back(value);    
    }

    vector<int> axisCopy = axis;

    sort(axis.begin(), axis.end());
    axis.erase(unique(axis.begin(), axis.end()), axis.end());

    for(int i = 0; i < axisCopy.size(); i++) {
        vector<int>::iterator iter = lower_bound(axis.begin(), axis.end(), axisCopy[i]);

        int index = iter - axis.begin();
        cout << index << ' ';
    } 
}