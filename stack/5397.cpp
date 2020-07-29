#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void){
    int t;

    cin >> t;

    while(t--){
        string str;
        list<char> ans;

        cin >> str;

        list<char>::iterator it = ans.end();

        for(int i = 0; i < str.length(); i++){
            if(str[i] == '<'){
                if(it == ans.begin()){
                    continue;
                }
                it--;
            } else if(str[i] == '>' ){
                if(it == ans.end()) {
                    continue;
                }
                it++;
            } else if(str[i] == '-'){
                if(it == ans.begin()) {
                    continue;
                }
                it = ans.erase(--it);
            } else {
                ans.insert(it, str[i]);
            }
        }

        for(list<char>::iterator iter = ans.begin(); iter != ans.end(); iter++){
            cout << *iter;
        }
        cout << '\n';
        ans.clear();
    }
}