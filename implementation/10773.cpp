#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int K;
    cin >> K;


    vector<int> result;
    for(int i = 0; i < K; i++){
        int value;
        cin >> value;

        if(value == 0) {
            result.pop_back();
        } else {
            result.push_back(value);
        }
    }

    int sum = 0;

    for(int i = 0; i <result.size(); i++) {
        sum += result[i];
    }

    cout << sum << '\n';
}