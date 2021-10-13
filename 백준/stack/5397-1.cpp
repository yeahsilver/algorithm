#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void){
    int test_case;

    cin >> test_case;

    while(test_case--){
        string password;
        list<char> passwordList;

        cin >> password;

        list<char>::iterator iterator = passwordList.end();

        for(int i = 0; i < password.length(); i++){
            if(password[i] == '<'){
                if(iterator == passwordList.begin()){
                    continue;
                }
                iterator--;

            } else if(password[i] == '>'){
                if(iterator == passwordList.end()){
                    continue;
                }
                iterator++;

            } else if (password[i] == '-'){
                if(iterator == passwordList.begin()){
                    continue;
                }
                iterator = passwordList.erase(--iterator);

            } else {
                passwordList.insert(iterator, password[i]);
            }
        }

        for(list<char>::iterator iter = passwordList.begin(); iter != passwordList.end(); iter++){
            cout << *iter;
        }
        cout << '\n';

        passwordList.clear();
    }
}