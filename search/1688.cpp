#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    int leftCnt = 1;
    int rightCnt = 1;

    vector<int> trophy;

    cin >> N;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        trophy.push_back(input);
    }

    int leftMax = trophy[0];
    int rightMax = trophy[N-1];

    for(int i = 1; i < N; i++){
        if(leftMax < trophy[i]){
            leftMax = trophy[i];
            leftCnt++;
        }
    }

    for(int i = N-2; i >= 0; i--){
        if(rightMax < trophy[i]){
            rightMax = trophy[i];
            rightCnt++;
        }
    }

    cout << leftCnt << '\n';
    cout << rightCnt << '\n';
    
}