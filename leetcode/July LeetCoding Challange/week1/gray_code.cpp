#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned int convertGrayCode(unsigned int num) {
    return (num>>1) ^ num;
}

vector<int> grayCode(int n) {
    vector<int> result;

    for(unsigned int i = 0; i < pow(2, n); i++) {
        result.push_back(convertGrayCode(i));
    }

    return result;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> result = grayCode(n);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}