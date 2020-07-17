#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 알고리즘 순서
    1. 수열 입력
    2. 처음 숫자(=1) 삽입
    3. for 문 돌려서 
*/
int main(void){
    int num;
    int cnt = 1;

    vector<int> sequence;
    vector<int> result;
    stack<int> stack;
    
    cin >> num;
    for(int i = 0; i < num; i++){
        int input;
        cin>>input;
        sequence.push_back(input);
    }

    result.push_back(1);
    
    
}