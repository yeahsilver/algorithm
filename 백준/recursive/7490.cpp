#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int value;

void make_zero(int sum, int op, int num, int cnt, string str){
    if(value == cnt){
        sum += (num * op);
        if(sum == 0){
           cout << str << '\n';
        }
    } else {
        cnt++;
        string str1 = to_string(cnt);
    
        make_zero(sum, op, (num*10)+cnt, cnt, str+" "+ str1);
        make_zero(sum + (num * op), 1, cnt, cnt, str+"+"+str1);
        make_zero(sum + (num * op), -1, cnt, cnt, str+"-"+str1);
    }
}

int main(void){
    int test_case;
    cin >> test_case;

    while(test_case--){
        cin >> value;
        make_zero(0, 1, 1, 1, "1");
        cout << '\n';
    }
}