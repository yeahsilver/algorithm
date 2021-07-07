#include <iostream>
#include <vector>

using namespace std;

int MAX = 100001;

int minSetSize(vector<int>& arr) {
    int size = arr.size();

    if(size == 0) {
        return 0;
    }

    vector<int> numbers(MAX, 0);

    for(int i = 0; i < arr.size(); i++) {
        numbers[arr[i]]++;
    }

    sort(numbers.begin(), numbers.end(), greater<int>());

    int sum = 0;
    int value = 0;

    for(value = 0; value < MAX; value++) {
        sum+=numbers[value];

        if(sum >= size/2) {
            break;
        }
    }

    return value+1;
}

int main(void) {
    vector<int> arr;

    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(7);

    cout << minSetSize(arr) << '\n';
}