#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, number;
    cin >> n >> number;

    vector<int> numbers;
    while(n != 0) {
        numbers.push_back(n%number);
        n/=number;
    }

    for(int i = numbers.size()-1; i >= 0; i--) {
        int value = numbers[i];
        if(0 <= numbers[i] && numbers[i] < 10) {
            cout << value;
        } else {
            cout << char('A'+numbers[i]-10);
        }
    }
}