#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 500001

int main(void) {
    int num;
    cin >> num;

    int numbers[MAX];
    int sum = 0;
   
    for(int i = 0; i < num; i++) {
        int value;
        cin >> value;
        sum += value;

        numbers[i] = value;
    }

    // 1. 산술 평균
    float avg = (round(((float)sum)/num));

    if (avg == 0) {
        avg = abs(avg);
    }

    cout << avg << '\n';

    sort(numbers, numbers+num);

    // 2. 중앙값
    cout << numbers[(num-1)/2] << '\n';

    // 3. 최빈값
    int maximum = 0;
    vector<int> v;

    int index = 0;
    while(1) {
        if(index > num-1) {
            break;
        }

        int value = upper_bound(numbers, numbers+num, numbers[index])-lower_bound(numbers, numbers+num, numbers[index]);
       
        if(maximum < value) {
            maximum = value;
            v.clear();
            v.push_back(numbers[index]);
        } else if(maximum == value) {
            v.push_back(numbers[index]);
        }

        index += value;
    }

    v.size() > 1 ? cout << v[1] << '\n' : cout << v[0] << '\n';

    // 4. 최댓값과 최소값의 차이
    cout << numbers[num-1]-numbers[0] << '\n';
}