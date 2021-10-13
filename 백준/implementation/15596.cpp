#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int>& a) {
    long long sum = 0;

    for(int i = 0; i < a.size(); i++) {
        sum+=a[i];
    }

    return sum;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> a;

    for(int i = 0; i < n; i++) {
        long long value;
        cin >> value;
        a.push_back(value);
    }

    cout << sum(a) << '\n';

    return 0;
}