#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> integers;
    integers.push_back(A);
    integers.push_back(B);
    integers.push_back(C);

    sort(integers.begin(), integers.end());

    cout << integers[1] << '\n';
    
}