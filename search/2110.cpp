/*
    배열에 숫자를 넣고, 이분 탐색 진행
    최소, 최대 gap을 설정하고, mid로 중간 값을 가지고 옴.
    for문을 돌려 count >= c 면 더 간격이 넓게 설치 할 수 있는지 확인 (left = mid + 1)
    아니면 right = mid -1해서 gap을 줄임.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, C;
    int result = 0;

    vector<int> home;

    cin >> N >> C;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        home.push_back(input);
    }

    sort(home.begin(), home.end());

    int left = home[1] - home[0];
    int right = home.back() - home.front();

    while(left <= right){
        int mid = (left + right) / 2;
        int value = home[0];
        int count = 1;

        for(int i = 1; i < N; i++){
            if(home[i] >= value + mid){
                value = home[i];
                count++;
            }
        }
        
        if(count >= C){
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << result << '\n';
}