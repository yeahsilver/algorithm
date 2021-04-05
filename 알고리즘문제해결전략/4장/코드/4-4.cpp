#include <iostream>
#include <vector>

using namespace std;

// 이중 for문을 사용하지 않고 이동 평균을 구하는 방법
// 1. 초기 range에 속하는 값을 미리 받아놓는다. 
// 2. for문이 돌아가면서 맨 첫번쨰에 있는 값을 빼서 중복으로 더해지는 값을 없앤다.
// 3. 다음 값을 더해 이동 평균 벡터에 삽입한다.

int main(void){
    int number, range;

    cout << "측정치의 개수를 입력하세요: ";
    cin >> number;

    cout << "이동 평균을 구할 범위를 입력하세요: ";
    cin >> range;

    cout << "\n데이터를 입력하세요 \n";

    vector<int> data;

    for(int i = 0; i < number; i++) {
        int value;
        cin >> value;

        data.push_back(value);
    }

    int sum = 0;

    for(int i = 0; i < range-1; i++) {
        sum += data[i];
    }

    vector<int> moving_average;

    for(int i = range - 1; i < number; i++) {
        sum += data[i];

        moving_average.push_back(sum/range);

        sum-= data[i-range+1];
    }

    cout << "\n이동 평균 입니다.\n";

    for(int i = 0; i < moving_average.size(); i++) {
        cout << moving_average[i] << ' ';
    }
}