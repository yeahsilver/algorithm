#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int number;
    
    cout << "입력할 숫자의 개수를 입력하세요: ";
    cin >> number;

    vector<int> data;

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        data.push_back(value);    
    }

    // 1. for문을 돌려 같은 값이 있으면 count ++    
    // 2. for문 돌린 후 count가 이전의 카운트 수보다 더 크면 max = count max_value =  value로 변환

    int max_cnt = 0;
    vector<int> max_value;

    for(int i = 0; i < number; i++) {
        int cnt = 0;
        int value = data[i];

        for(int j = 0; j < number; j++) {
            if (value == data[j]) {
                cnt++;
            }
        }

        if (max_cnt < cnt) {
            max_value.clear();
            max_cnt = cnt;
            max_value.push_back(value);
            
        } else if (max_cnt == cnt) {
            max_value.push_back(value);
        }
    }

    max_value.erase(unique(max_value.begin(), max_value.end()), max_value.end());
    
    cout << "가장 많이 등장하는 숫자\n";

    for(int i = 0; i < max_value.size(); i++) {
        cout << max_value[i] << ' ';
    }
}