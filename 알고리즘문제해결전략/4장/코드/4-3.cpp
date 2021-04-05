#include <iostream>
#include <vector> 

using namespace std;

int main(void) {
    int number, range;

    cout << "측정치의 개수를 입력하세요: ";
    cin >> number;

    cout << "이동 평균을 구할 범위를 입력하세요: ";
    cin >> range;

    cout << "\n데이터를 입력하세요 \n";

    vector<int> data;

    for (int i = 0; i < number; i++) {
         int value;
         cin >> value;

         data.push_back(value);
    }

    vector<int> moving_average;

    for(int i = range-1; i < number; i++) {
        int sum = 0;

        for (int j = 0; j < range; j++) {
            sum += data[i-j];
        }

        moving_average.push_back(sum/range);
    }

    cout << "\n이동 평균 입니다.\n";

    for(int i = 0; i < moving_average.size(); i++) {
        cout << moving_average[i] << "\t";
    } 
}