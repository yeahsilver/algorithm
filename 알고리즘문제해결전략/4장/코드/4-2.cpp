#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int number;

    cout << "입력하고 싶은 값의 개수를 입력하세요: ";
    cin >> number;

    vector<int> data;

    cout << "\n값을 입력하세요 \n";

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        data.push_back(value);
    }

    // O(n*logn)의 시간복잡도를 가짐
    sort(data.begin(), data.end());

    int max_number = 0;
    
    vector<int> max_value;

    for(int i = 0; i < number; i++) {
        // upper_bound / lower_bound 각각 O(logN)
        int num = upper_bound(data.begin(), data.end(), data[i]) - lower_bound(data.begin(), data.end(), data[i]);
        if (max_number < num) {
            max_value.clear();

            max_number = num;
            max_value.push_back(data[i]);

        } else if (max_number == num) {
            max_value.push_back(data[i]);
        }
    }
    
    max_value.erase(unique(max_value.begin(), max_value.end()), max_value.end());

    cout << "가장 많이 등장하는 숫자\n";

    for(int i = 0; i < max_value.size(); i++) {
        cout << max_value[i] << ' ';
    }   
}
