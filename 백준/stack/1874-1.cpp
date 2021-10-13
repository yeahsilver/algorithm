#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    int cnt = 0;
    int index = 0;

    vector<char> op;
    vector<int> sequence;
    vector<int> result;

    stack<int> stack;

    cin >> num;

    for(int i = 0; i < num; i++){
        int input;
        cin >> input;
        sequence.push_back(input);
    }

    for(int i = 1; i <= num; i++){
        stack.push(i);
        op.push_back('+');
        while(!stack.empty() && stack.top() == sequence[index]){
            stack.pop();
            op.push_back('-');
            index++;
        }
    }

    if(!stack.empty()){
        cout<<"NO\n";
    } else {
        for(int i = 0; i < op.size(); i++){
            cout<<op[i]<<'\n';
        }
    }
}