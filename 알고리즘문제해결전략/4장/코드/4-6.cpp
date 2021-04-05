#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int number;
    cin >> number;

    vector<int> result;

    if(number == 1) {
        cout << "1";
        return 0;
    }

    for(int i = 2; number > 1; i++){
        while(number % i == 0) {
            number/=i;
            result.push_back(i);
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}