#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    int n;
    int count = 1;
    stack<int> stack;
    vector<char> result;

    cin >> n;

    for(int i = 0; i < n; i++){
        int data;
        cin >> data;

        // 입력받은 데이터에 도달할 때 까지 삽입
        while(count <= data){ 
            stack.push(count);
            count++;
            result.push_back('+');
        }

        // 스택의 최상위 원소가 데이터와 같을 때 출력
        if(stack.top() == data){
            stack.pop();
            result.push_back('-');
        } else { // 남은 숫자가 내림차순이 아닐 경우
            cout<<"NO\n";
            exit(0);
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<'\n';
    }
}