#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    vector<string> result;
    for(int i = 0; i < str.size(); i++) {
        result.push_back(str.substr(i, str.size()) );
    }

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}