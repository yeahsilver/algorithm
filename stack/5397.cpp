#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

char Reverse(stack<char> stack){
    int size = stack.size();
    int cnt = 0;

    char* arr = new char[size];
    
    while(!stack.empty()){
        char value = stack.top();
        arr[cnt] = value;
        cnt++;
    }

    return arr[cnt - 1];
}

int main(void){
    int test_case;
    int cursor = 0;

    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        stack<char> left;
        stack<char> right;
        
        do{
            char input;
            cin >> input;

            if(input == '<'){
                char value;
                if(!left.empty()){
                    value = left.top();
                    left.pop();
                    right.push(value);
                }
            } else if(input == '>'){
                
            }
        }
        while(getc(stdin)== ' ');
    }

    



    
    
}
