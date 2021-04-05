#include <iostream>
#include <vector>

using namespace std;

int firstIndex(int value, vector<int> info) {
    for(int i = 0; i < info.size(); i++) {
        if(value == info[i]) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int number;

    cout << "배열의 크기를 입력하세요: ";
    cin >> number;

    vector<int> info;

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        info.push_back(value);
    }

    int search_value;

    cout << "찾을 값을 입력히세요: ";
    cin >> search_value;

    int index = firstIndex(search_value, info);

    if(index == -1) {
        cout << "값이 없습니다.\n";
    } else {
        cout << "찾을 값의 인덱스는 " << index << "입니댜.\n";  
    }

    return 0;
}