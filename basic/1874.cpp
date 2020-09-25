#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    int num;
    int cnt = 1;

    vector<char> op;
    stack<int> stack;

    cin >> num;

    for(int i = 0; i < num; i++){
        int data;
        cin >> data;

        while(cnt <= data){
            stack.push(cnt);
            cnt++;
            op.push_back('+');
        }

        if(stack.top() == data){
            stack.pop();
            op.push_back('-');
        } else {
            cout<<"NO\n";
            exit(0);
        }
    }

    for(int i = 0; i < op.size(); i++){
        cout<<op[i]<<'\n';
    }
}